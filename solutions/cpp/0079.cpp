class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ctr = 0;

    bool exist(vector<vector<char>>& board, string word) {
         for(int i=0; i<board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                if(backtrack(board, word, 0, i, j)) return true;
            }
         }
         return false;
    }

    bool backtrack(vector<vector<char>>& board, const string& word, int matched, int i, int j){
        if(matched == word.size()) return true;    
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[matched]) return false;

        char t = board[i][j];
        board[i][j] = '*';
        for(auto dir : dirs){
            int r = i + dir.first;
            int c = j + dir.second;
            if(backtrack(board, word, matched + 1, r, c)) return true;
        }
        board[i][j] = t;

        return false;
    }
};
