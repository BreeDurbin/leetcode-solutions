class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i < m; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for(int j=0; j < n; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O')board[i][j] = 'X';
                else if(board[i][j]=='U')board[i][j] = 'O';
            }
        }
        
    }

    void dfs(vector<vector<char>>& board, int i, int j){

        if(board[i][j] != 'O') return;
        board[i][j] = 'U';

        if(i > 0) dfs(board, i-1, j);
        if(j > 0) dfs(board, i, j-1);
        if(i < board.size() - 1) dfs(board, i+1, j);
        if(j < board[0].size() - 1) dfs(board, i, j+1);
    }
};
