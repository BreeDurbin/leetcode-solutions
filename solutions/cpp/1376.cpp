class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }

        return dfs(headID, adj, informTime);
    }

    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime){
        int ans = 0;
        for(auto & neigh : adj[node]){
            ans = max(ans, dfs(neigh, adj, informTime));
        }
        return ans + informTime[node];
    }
};
