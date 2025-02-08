

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        //build adj list
        vector<vector<tuple<int,int>>> adj(n);
        for(auto e : redEdges){
            adj[e[0]].push_back({e[1], 1});
        }

        for(auto e : blueEdges){
            adj[e[0]].push_back({e[1], 2});
        }

        //init ans/vis vectors
        vector<int> ans(n, -1);
        vector<bool> vis(n, 0);

        return bfs(n, adj);
    }

    vector<int> bfs(int n, vector<vector<tuple<int,int>>>& adj){

        //init ans/vis vectors
        vector<int> ans(n, -1);
        vector<bool> v1(n, 0), v2(n, 0);

        //init stack
        queue<tuple<int, int>> q;
        q.push({0, 1});
        q.push({0, 2});
        int level = 0;
        ans[0] = 0;

        while(!q.empty()){

            int sz = q.size();
            level++;

            for(int i=0; i<sz; i++){
                int node = get<0>(q.front()), color = get<1>(q.front()); q.pop();

                if(color == 1){
                    v1[node] = true;
                } else {
                    v2[node] = true;
                }

                for(auto & neighbor : adj[node]){
                    int neigh_node = get<0>(neighbor), neigh_color = get<1>(neighbor);
                    if(neigh_color == color) continue; // skip if visited or same color
                    if(neigh_color == 1 && v1[neigh_node]) continue;
                    if(neigh_color == 2 && v2[neigh_node]) continue;
                    q.push(neighbor);
                    if(ans[neigh_node] == -1) ans[neigh_node] = level;
                }
            }
        }

        return ans;

    }
};
