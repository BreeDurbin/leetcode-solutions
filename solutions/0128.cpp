class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, n = nums.size();

        unordered_map<int, bool> cache;

        for(auto& num : nums) cache[num] = true;

        for(int i=0; i<n; i++){
            if(cache[nums[i] - 1]) continue;
            int currentStreak = 1;
            int currentNum = nums[i];

            while(cache[++currentNum]){
                currentStreak++;
            }

            ans = max(ans, currentStreak);
        }
        
        return ans;
    }
};