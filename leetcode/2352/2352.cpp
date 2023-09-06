class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>rows;
        int n = grid.size();
        int pairs = 0;
        // Stick all rows in a hashmap
        // This will allow us to avoid 1 extra nested loop where we would be 
        //searching for all rows that match a column if we were to brute force.
        for(int i=0; i < n; i++){
            rows[to_str(grid, false, i)]++;
        }
        // Check how many row matches each column has in the rows table
        for(int i=0; i < n; i++){
            pairs += rows[to_str(grid, true, i)];
        }
        return pairs;
    }

    // If row_col = 0 then we will scan the row of our 2d array.
    // If row_col = 1 then we will scan the col of our 2d array.
    string to_str(vector<vector<int>>& vec, bool is_col = false, int row_col = 0){
        string str = "";
        //get string version of column
        if(is_col == true){
            for(int i = 0; i < vec.size();i++){
                str+=to_string(vec[i][row_col]) + "$";
            }
        }
        // get row version of column
        else{
            for(int i = 0; i < vec.size();i++){
                str+=to_string(vec[row_col][i]) + "$";
            }
        }
        return str;
    }
};