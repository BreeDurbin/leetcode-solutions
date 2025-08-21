class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                height[j] = mat[i][j] == 1 ? height[j] + 1 : 0;
            }

            for(int j=0; j<n; j++){
                
                if(height[j] > 0){
                    int min_y = INT_MAX;
                    for(int x=0; j-x>=0; x++){
                        min_y = min(height[j-x], min_y);
                        ans += min_y;
                    }
                }
            }
        }

        return ans;        
        
    }
};
