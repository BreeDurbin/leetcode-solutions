class Solution {
    unordered_map<string, vector<pair<string, double>>> adj_list;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        vector<double> result;
        for(int i=0; i<n; i++){
            adj_list[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            adj_list[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
        }
        for(int i=0; i<m; i++){
            unordered_map<string, bool> visited;
            result.push_back(dfs(queries[i][0], queries[i][1], visited));
        }
        return result;
    }

    double dfs(string start, string end, unordered_map<string, bool> &visited){
        //not found
        if(!adj_list[start].size() || visited[start]) return -1.0;
        //set visited
        visited[start] = true;
        //dfs all adjacent nodes
        for(int i=0; i<adj_list[start].size(); i++){
            pair<string, double> next_node = adj_list[start][i];
            // found
            if(next_node.first == end) return next_node.second;
            // dig deeper
            double result = dfs(next_node.first, end, visited);
            // recursive dfs found the node
            if(result != -1.0) return next_node.second * result;
        }
        return -1;
        
    }
};