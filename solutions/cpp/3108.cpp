class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        //build adjacency list
        vector<vector<pair<int,int>>> g(n);
        for(auto edge : edges){
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }

        //initialize member variables
        //queue
        queue<int> q;
        // visited
        vector<bool> vis(n, false);
        //id which serves an an index for which discrete graph the node is in
        int id = 0;
        //comp[node]=id
        // lets us given a node lookup an id which in turn tells us which graph we are on
        vector<int> comp(n);
        //given a 
        vector<int> answers(2*n);


        //bfs all nodes
        for(int i=0; i<n; i++){
            if(!vis[i]){
                q.push(i);
                //this variable will store the total cost of our traversal
                int ans = -1;
                vis[i] = true;

                set<pair<int,int>> vis_inner;
                //bfs
                while(!q.empty()){
                    int top = q.front();
                    comp[top] = id;
                    q.pop();
                    //add all edges connected to this node to the graph
                    for(int j=0; j < g[top].size(); j++){
                        if(vis_inner.count(g[top][j]) == 0){
                            vis[g[top][j].first] = true;
                            q.push(g[top][j].first);
                            if(ans == -1){
                                ans = g[top][j].second;
                            } else {
                                ans &= g[top][j].second;
                            }
                            vis_inner.insert(g[top][j]);
                        }
                    }
                }
                answers[id] = ans;
                id++;
            }
        }

        vector<int> ans;
        for(auto q : query){
            //starting ans ending position the same
            if(q[0] == q[1]) ans.push_back(0);
            //start and end are in the same sub graph
            else if(comp[q[0]]==comp[q[1]]) ans.push_back(answers[comp[q[0]]]);
            // no connection 
            else ans.push_back(-1);
        }

        return ans;
    }
};