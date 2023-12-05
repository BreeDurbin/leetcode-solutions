class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        int ans = 0, sum = 0;
        sort(nums.begin(), nums.end());

        for(auto &num : nums){
            if(sum >= n) break;
            while(num > sum + 1 && sum < n){
                sum += sum  + 1;
                ans++;
            }
            sum += num;
        }

        while(sum < n){
            sum += sum + 1;
            ans++;
        }

        return ans;
        
    }
};