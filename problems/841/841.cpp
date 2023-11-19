class Solution {
public:
    unordered_map<int,int> visited;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return visit(rooms,0) == rooms.size();
    }

    int visit(vector<vector<int>>& rooms, int key){
        visited[key]++;
        int i=1;
        for(int key : rooms[key]){
            if(visited[key] > 0) continue;
            i += visit(rooms, key);
        }
        return i;
    }
};