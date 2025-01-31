class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
            if(colors[i] == 0 && !is_bipartite_component(graph, colors, i)) return false;
        }
        return true;
    }

    bool is_bipartite_component(vector<vector<int>>& graph, vector<int> colors, int i){

        if(colors[i]) return true;
        queue<int> q;
        q.push(i);
        colors[i] = 1;

        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto neighbor : graph[node]){
                if(colors[node] == colors[neighbor]){
                    return false;
                } else if(!colors[neighbor]){
                    colors[neighbor] = (-1) * colors[node];
                    q.push(neighbor);
                }
            }
        }

        return true;
    }
};
