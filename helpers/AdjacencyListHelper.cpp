vector<vector<int>> adjacencyList(vector<vector<int>>& edges) {
    vector<vector<int>> al(edges.size() + 1);
    for (auto &e: edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);            
    }        
    return al;
}
