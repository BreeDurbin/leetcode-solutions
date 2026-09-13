class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int count = 0;
        int n = img1.size();

        for(int i=-(n-1); i<n; i++){
            for(int j=-(n-1); j<n; j++){
                int overlap = count_overlap(img1, img2, i, j);
                count = max(count, overlap);
            }
        }

        return count;
    }

    int count_overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int i_shift, int j_shift){
        int count = 0;
        int n = img1.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j < n; j++){
                int i2 = i + i_shift;
                int j2 = j + j_shift;

                if(i2 < n && i2 >= 0 && j2 < n && j2 >=0){
                    if(img1[i][j] && img2[i+i_shift][j+j_shift]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
