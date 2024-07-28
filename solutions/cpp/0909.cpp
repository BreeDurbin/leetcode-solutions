class Solution {
public:

    queue<pair<int, int>> q; // square, moves
    unordered_map<int, bool> visited;

    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        int n = board.size(), goal = board.size()*board.size();
        q.push({1, 0});
        while(!q.empty()){
            auto pos = q.front();
            q.pop();
            for(int i = 1; i<=6; i++){
                //cout << "hiya pos: " << pos.first << " count " << pos.second << endl;
                int next = pos.first + i;
                auto target = getPos(next, n);
                if(board[target.first][target.second] != -1) next = board[target.first][target.second];
                if(next == goal) return pos.second + 1;
                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, pos.second + 1});
                }
            }
        }

        return -1;
    }

    pair<int, int> getPos(int square, int n){
        int row = (square-1) / n;
        int col = (square-1) % n;
        if(row % 2) col = n - 1 - col;
        return {row, col};
    }

};