class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> in_degree(n, 0), ans;
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(auto node : graph[i]){
                adj[node].push_back(i);
                in_degree[i]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++) if(in_degree[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neighbor : adj[node]){
                if(!--in_degree[neighbor]) q.push(neighbor);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;

    }
};
