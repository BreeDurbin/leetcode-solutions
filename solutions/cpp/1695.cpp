class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> s;
        int left = 0, right = 0;
        int running_total = 0;

        while(right < n){
            
            //collapse the left and decrese running total
            while(left < right && s.find(nums[right]) != s.end()){
                running_total -= nums[left];
                s.erase(nums[left++]);
            }

            //expand out to the right
            while(right < n && s.find(nums[right]) == s.end()){
                running_total += nums[right];
                s.insert(nums[right++]);
            }
            
            //update running total
            ans = max(ans, running_total);

        }

        return ans;
    }
};
