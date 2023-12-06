class Solution {
    unordered_map<int, int> jump_cache;
public:
    bool canJump(vector<int>& nums) {
        int best_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(best_sum < i) return false;
            best_sum = max(best_sum, i + nums[i]);
        }
        return best_sum >= nums.size() - 1 ? true : false;
    }
};