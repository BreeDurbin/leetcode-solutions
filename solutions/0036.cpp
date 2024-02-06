class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<char, int>> rows, columns;
        unordered_map<pair<int, int>, unordered_map<char, int>, hash_pair> squares;

        for(int row = 0; row < 9; row++){
            for(int column = 0; column < 9; column++){
                
                if(board[row][column] == '.') continue;
                
                if( rows[row][board[row][column]] == 1 
                    || columns[column][board[row][column]] == 1 
                    || squares[{row/3, column/ 3}][board[row][column]] == 1 ) return false;
                
                rows[row][board[row][column]]++;
                columns[column][board[row][column]]++;
                squares[{row/3, column/3}][board[row][column]]++;
            }
        }

        return true;        
    }
private: 
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
    
            if (hash1 != hash2) {
                return hash1 ^ hash2;              
            }
            
            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };
};