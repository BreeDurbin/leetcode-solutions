class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> prefixMax(n);
        prefixMax[0] = values[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1], i + values[i]);
        }
        int ans = 0;
        for(int j=1;j<n;j++){
            ans = max(ans, values[j] - j + prefixMax[j-1]);
        }
        return ans;
    }
};
