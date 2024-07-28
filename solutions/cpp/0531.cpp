class Solution {
    
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int rows = picture.size(), cols = picture[0].size(), ans=0;
        vector<int> row_b_count(rows), col_b_count(cols);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(picture[r][c] == 'B'){
                    row_b_count[r]++;
                    col_b_count[c]++;
                }
            }
        }
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(row_b_count[r] == 1 && col_b_count[c] == 1 && picture[r][c] == 'B'){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};