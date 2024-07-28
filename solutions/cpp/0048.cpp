class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int t = 0, l = 0, r = m[0].size() - 1, b = m.size() - 1;

        while(l < r){
            for(int i = 0; i < r - l; i++){
                int t1 = m[t][l+i], t2 = m[t+i][r], t3 = m[b][r-i], t4 = m[b-i][l];
                m[t][l+i] = t4;
                m[t+i][r] = t1;
                m[b][r-i] = t2;
                m[b-i][l] = t3;
            }
            t++;
            l++;
            r--;
            b--;
        }
    }
};