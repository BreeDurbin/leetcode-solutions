class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = prerequisites.size();
        vector<vector<bool>> is_reachable(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<bool> ans;

        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0; i<adj.size(); i++){
            q.push(i);
            vector<int> visited(adj.size());
            visited[i] = 1;
            while(!q.empty()){
                int node = q.front(); q.pop();

                for(auto neighbor : adj[node]){
                    if(visited[neighbor]) continue;
                    visited[neighbor] = 1;
                    is_reachable[neighbor][i] = true;
                    q.push(neighbor);
                }
            }

        }

        for(auto q : queries) ans.push_back(is_reachable[q[0]][q[1]]);

        return ans;
    }
};
