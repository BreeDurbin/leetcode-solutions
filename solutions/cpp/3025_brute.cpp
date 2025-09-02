class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int ix = points[i][0], iy = points[i][1];
            for(int j=0; j<n; j++){
                if(i == j) continue;
                int jx = points[j][0], jy = points[j][1];
                if(jy > iy || jx < ix) continue;

                bool is_valid_sq = true;
                for(int k=0; k<n; k++){
                    if(k == i || k == j) continue;
                    int kx = points[k][0], ky = points[k][1];
                    if(kx >= ix && kx <= jx && ky <= iy && ky >= jy){
                        is_valid_sq = false;
                        break;
                    }
                }
                if(is_valid_sq) ans++;
            }
        }

        return ans;
    }
};
