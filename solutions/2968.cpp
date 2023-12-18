typedef long long ll;

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, ll k) {
        int left = 0, n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        long cur = 0;
        for(int right = 0; right < n; right++){
            cur += nums[right] - nums[(left + right) / 2];
            while(cur > k) {
                cur -= nums[(left + right + 1) / 2] - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};