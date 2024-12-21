class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n <= 1) return 1;
        // initialize
        int component = 0;
        vector<vector<int>> neighbors(n);
        vector<int> degree(n, 0);
        vector<long long> componentValues(values.begin(), values.end());
        queue<int> q;

        //build adj list
        for(auto & edge : edges){
            int u = edge[0], v = edge[1];
            neighbors[u].push_back(v);
            degree[u]++;
            neighbors[v].push_back(u);
            degree[v]++;
        }

        //populate queue with nodes of in degree 1 (leaf nodes)
        for(int i=0; i<n; i++){
            if(degree[i] == 1) q.push(i);
        }

        //while not empty loop
        while(!q.empty()){
            int t = q.front();
            q.pop();
            degree[t]--;

            long long tValue = 0;
            if(componentValues[t] % k == 0){
                component++;
            } else {
                tValue = componentValues[t];
            }

            for(int neighbor : neighbors[t]){
                if(degree[neighbor] > 0){
                    degree[neighbor]--;
                    componentValues[neighbor] += tValue;
                    if(degree[neighbor] == 1) q.push(neighbor);
                }
            }
        }

        return component;
        
    }
};
