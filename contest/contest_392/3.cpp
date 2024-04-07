class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){
            //cout << k << endl;
            return abs(k - nums[0]);
        }
        auto m = nums.begin() + nums.size() / 2;
        std::nth_element(nums.begin(), m, nums.end());
        int median = nums[nums.size() / 2];
        
        long long ans = 0;
        
        while(median != k){
            std::nth_element(nums.begin(), m, nums.end());
            int median = nums[nums.size() / 2];
            //cout << "hi" << endl;
            if(median != k){
                //cout << "hi1" << endl;
                ans += abs(k - nums[nums.size() / 2]);
                nums[nums.size() / 2] = k;
            }
            else break;
        }
        
        return ans;
    }
};