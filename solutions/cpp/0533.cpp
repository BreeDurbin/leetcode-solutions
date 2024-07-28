class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int rows = picture.size(), cols = picture[0].size(), ans=0;
        vector<int> row_b_count(rows), col_b_count(cols);
        vector<string> patterns(rows);
        unordered_map<string, int> pattern_count;
        for(int r=0; r<rows; r++){
            string pattern = "";
            for(int c=0; c<cols; c++){
                if(picture[r][c] == 'B'){
                    row_b_count[r]++;
                    col_b_count[c]++;
                }
                pattern += picture[r][c];
            }
            patterns[r] = pattern;
            pattern_count[pattern]++;
        }
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(row_b_count[r] == target && pattern_count[patterns[r]] == target && col_b_count[c] == target && picture[r][c] == 'B'){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};