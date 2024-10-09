class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int l = 0, r = m.size() * m[0].size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int row = mid / m[0].size();
            int col = mid % m[0].size();
            int cur = m[row][col];
            if(cur == t) return true;
            else if(t < cur) r = mid - 1;
            else l = mid + 1;
        }

        return false;
        
    }
};
