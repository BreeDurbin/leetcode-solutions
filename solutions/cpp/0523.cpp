class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return false;
        unordered_map<int,int> r_map;
        r_map[0] = -1;
        
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
            int remainder = total % k;
            if(r_map.find(remainder) == r_map.end()) r_map[remainder] = i;
            else if(i - r_map[remainder] > 1) return true;
        }
        
        return false;
    }
};