class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for(int i = 0; i < gain.size(); i++){
            cur += gain[i];
            ans = max(ans,cur);
        }
        return ans;
    }
};