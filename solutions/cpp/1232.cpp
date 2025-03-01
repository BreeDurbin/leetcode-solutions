class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int m = coordinates.size();
        if(m == 2) return true;

        int d_y = coordinates[1][1] - coordinates[0][1];
        int d_x = coordinates[1][0] - coordinates[0][0];
        int y0 = coordinates[0][1];
        int x0 = coordinates[0][0];

        for(int i=2; i<m; i++){
            auto p = coordinates[i];
            if(d_x*(p[1] - y0) != d_y*(p[0] - x0)) return false;
        }

        return true;
    }
};
