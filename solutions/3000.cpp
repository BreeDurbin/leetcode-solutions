class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int max_diag = 0, max_area = 0;

        for(int i = 0; i<n; i++){
            const vector<int>& dim = dimensions[i];

            int diag = dim[0] * dim[0] + dim[1] * dim[1];
            int area = dim[0] * dim[1];

            if(diag > max_diag){
                max_diag = diag;
                max_area = area;
            }
            else if(diag == max_diag){
                max_area = max(max_area, area);
            }

        }

        return max_area;
    }
};
