class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int XOR = 0;

        for(auto num : nums) XOR ^= num;

        if(XOR > 0) return nums.size();
        if(XOR == 0) for(auto num : nums) {if(num != 0) return nums.size() - 1;}

        return 0;
    }
};
