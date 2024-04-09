class Solution {

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        stack<pair<int,int>> s;
        //int rows = board.size(), cols = board[0].size();
        s.push({click[0], click[1]});

        while(!s.empty()){
            auto square = s.top();
            s.pop();
            if(board[square.first][square.second]=='E'){
                int count = adjacent(square.first, square.second, board, s);
                board[square.first][square.second] = count > 0 ? to_string(count)[0] : 'B';
            }
        }

        return board;
    }

    int adjacent(int row, int col, vector<vector<char>> board, stack<pair<int, int>> &s){
        // for each adjacent square that is 'E' add to the stack;
        int count = 0, rows = board.size(), cols = board[0].size();

        for(const auto & [d_row, d_col] : dirs){
            int t_row = row + d_row;
            int t_col = col + d_col;
            if(t_row < 0 || t_row == rows || t_col < 0 || t_col == cols) continue;
            if(board[t_row][t_col] == 'M') ++count;
        }
        if(!count){
            for(const auto & [d_row, d_col] : dirs){
                int t_row = row + d_row;
                int t_col = col + d_col;
                if(t_row < 0 || t_row == rows || t_col < 0 || t_col == cols) continue;
                s.push({t_row, t_col});
            }
        }

        return count;
    }

    private:
      const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},   {1, -1}, {1, 0},  {1, 1}};
};