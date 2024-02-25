class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> nums_count;
        for(auto num : nums){
            if(++nums_count[num] > 2) return false;
        }
        return true;
    }
};