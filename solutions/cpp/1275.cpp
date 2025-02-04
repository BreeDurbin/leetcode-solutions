class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        int turn = 0;

        for(auto move : moves){
            board[move[0]][move[1]] = (turn % 2 == 0) ? 'A' : 'B';
            turn++;
        }

        if(eval(board, 'A')) return "A";
        if(eval(board, 'B')) return "B";

        if(moves.size() == 9) return "Draw";
        return "Pending";
    }

    bool eval(vector<vector<char>> & grid, char c){
        for(int i=0; i<3; i++){
            if(grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) return true;
            if(grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) return true;
        }
        return (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) ||
               (grid[2][0] == c && grid[1][1] == c && grid[0][2] == c);
    }
};
