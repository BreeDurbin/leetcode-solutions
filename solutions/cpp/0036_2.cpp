class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[9][9] = {0}, col[9][9] = {0}, sq[9][9] = {0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1', k = i/3*3 + j/3;
                    if(row[i][num]++ || col[j][num]++ || sq[k][num]++) return false;
                }
            }
        }

        return true;
    }
};
