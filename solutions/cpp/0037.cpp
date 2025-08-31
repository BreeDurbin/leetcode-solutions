class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }

    bool solve(vector<vector<char>>& board){
        //try all cells in the board
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                // if a cell is empty try all possible digits
                if(board[i][j] == '.'){
                    for(char k='1'; k<='9'; k++){
                        if(is_valid_move(i, j, board, k)){
                            //out << "inserting k: " << k << " at " << i << "," << j << endl;
                            board[i][j] = k;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    bool is_valid_move( int row, int col, vector<vector<char>>& board, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
