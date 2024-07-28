class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> times;
        for(int i=0; i<n; i++){
            times.push_back(stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2)));
        }
        sort(times.begin(), times.end());
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            ans = min(ans, times[i] - times[i-1]);
        }

        ans = min(ans, 24*60 - times[n-1] + times[0]);
        
        return ans;
    }
};