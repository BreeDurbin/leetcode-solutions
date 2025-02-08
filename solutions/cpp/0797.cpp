class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int target = graph.size() - 1;
        vector<int> path;
        path.push_back(0);
        dfs(ans, 0, graph, target, path);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, int node, vector<vector<int>>& adj, int target, vector<int>& path){
        if(target == node){ 
            ans.push_back(path);
            return;
        }

        for(auto & neigh : adj[node]){
            path.push_back(neigh);
            dfs(ans, neigh, adj, target, path);
            path.pop_back();
        }
    }
};
