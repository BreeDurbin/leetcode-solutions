class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges1.size() + 1, n = edges2.size() + 1;
        vector<vector<int>> adj1 = adjacencyList(edges1), adj2 = adjacencyList(edges2);
        vector<int> ans(m);

        int count = 0;
        for(int i=0; i<n; ++i){
            count = max(count, dfs(i, -1, adj2, k - 1));
        }

        for(int i=0; i<m; ++i){
            ans[i] = count + dfs(i, -1, adj1, k);
        }
        
        return ans;
    }

    vector<vector<int>> adjacencyList(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);            
        }        
        return adj;
    }

     int dfs(int node, int parent, vector<vector<int>> &graph, int hops){
         if(hops <= 0) return hops == 0;
         int i = 1;
         for(int neighbor : graph[node]){
            if(neighbor != parent){
                i += dfs(neighbor, node, graph, hops - 1);
            }
         }
         return i;
     }
};
