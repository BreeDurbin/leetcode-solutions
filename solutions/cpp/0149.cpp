class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int ans = 1;

        for(int i = 0; i<n; i++){
            unordered_map<double,int> count;
            int maxi = 0;
            for(int j = i + 1; j<n; j++){
                if(j == i) continue;

                double slope = INT_MIN;
                if(points[j][0] == points[i][0]) slope = INT_MAX;
                else {
                    slope = (double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]);
                }

                count[slope]++;
                maxi = max(maxi, count[slope]);
            }
            ans = max(ans, maxi + 1);
        }

        return ans;
    }
};
