class Solution {
public:
    unordered_map<int,int> visited;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i] == 0){
                count++;
                visit(isConnected,i);
            }
        }
        return count;
    }

    void visit(vector<vector<int>>& isConnected, int i){
        visited[i]++;
        for(int j=0; j<isConnected[i].size(); j++){
            if(visited[j] > 0) continue;
            if(isConnected[i][j] == 1) visit(isConnected, j);
        }
    }
    
};