class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> frequency;
        int left = 0, right = 0;
        int n = nums.size();
        long long ans = 0;

        while(right < n){
            frequency[nums[right]]++;

            while(frequency.rbegin()->first - frequency.begin()->first > 2){
                frequency[nums[left]]--;
                if(frequency[nums[left]] == 0){
                    frequency.erase(nums[left]);
                }
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};
