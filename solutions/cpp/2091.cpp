class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        int min_i = min_element(nums.begin(), nums.end()) - nums.begin();        
        int max_i = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(min_i, max_i);
        int right = max(min_i, max_i);

        return min({right + 1, n - left, left + 1 + n - right});
    }
};
