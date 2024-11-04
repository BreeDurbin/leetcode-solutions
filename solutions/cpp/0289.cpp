class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int cols = board[0].size(), rows = board.size();

        //Encoding step
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                board[i][j] = encode(board, i, j);
            }
        }

        //Decoding step
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                //decode here
                board[i][j] = decode(board[i][j]);
            }
        }

    }
private:
    int encode(vector<vector<int>> board, int row, int col){
        int cols = board[0].size() - 1, rows = board.size() - 1;
        int count = 0;
        //top left
        if(row > 0 && col > 0 && (board[row-1][col-1] == 1 || board[row-1][col-1] == 3)) count++;
        // top middle
        if(row > 0 && (board[row-1][col] == 1 || board[row-1][col] == 3)) count++;
        // top right
        if(row > 0 && col < cols && (board[row-1][col+1] == 1 || board[row-1][col+1] == 3)) count++;
        // center right
        if(col < cols && (board[row][col+1] == 1 || board[row][col+1] == 3)) count++;
        // bottom right
        if(col < cols && row < rows && (board[row+1][col+1] == 1 || board[row+1][col+1] == 3)) count++;
        // bottom center
        if(row < rows && (board[row+1][col] == 1 || board[row+1][col] == 3)) count++;
        // bottom left
        if(row < rows && col > 0 && (board[row+1][col-1] == 1 || board[row+1][col-1] == 3)) count++;
        // center left
        if(col > 0 && (board[row][col-1] == 1 || board[row][col-1] == 3)) count++;

        //orig | new | res
        //  0     0     0
        //  1     0     1
        //  0     1     2
        //  1     1     3

        int ans = board[row][col];
        if(board[row][col] && (count == 2 || count == 3)) ans = 3;
        else if(count == 3) ans = 2;

        return ans;
    }

    int decode(int cell){
        //orig | new | res
        //  0     0     0
        //  1     0     1
        //  0     1     2
        //  1     1     3
        if(cell == 2 || cell == 3) return 1;
        return 0;
    }

};
