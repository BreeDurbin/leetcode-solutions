class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size(), m = topRight.size();
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j == i) continue;
                int x_distance = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int y_distance = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                //cout << " i "  << i << " j "  << j << " x_distance " << x_distance << " y dist " << y_distance << endl;
                if(x_distance > 0 && y_distance > 0){
                    //cout << " i "  << i << " j "  << j << " x_distance " << x_distance << " y dist " << y_distance << endl;
                    long long side = min(x_distance, y_distance);
                    ans = max(side * side, ans);
                }
            }
        }
        
        return ans;
        
    }
};