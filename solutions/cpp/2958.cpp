class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        if(nums.size()==1) return 1;

        unordered_map<int,int> f;

        // for (const auto& [key, value] : f) {
        //     std::cout << "Key: " << key << ", Value: " << value << '\n';
        // }

        int ans = 0;

        for(int right = 0, left = 0; right < nums.size(); right++){
            f[nums[right]]++;
            while(f[nums[right]] > k){
                f[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
