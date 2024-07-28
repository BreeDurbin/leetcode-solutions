class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int width) {        
        
        int ans = 0;
        
        sort(points.begin(), points.end());
        
        for(int left=0, right=0; right<points.size(); right++){
            if(points[right][0] - points[left][0] > width){
                ans++;
                left = right;
            }
        }
        
        return ++ans;
    }
};
