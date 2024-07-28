
class Solution {
public:
    unordered_map<int,int> mp;
    int numberOfPoints(vector<vector<int>>& nums) {
        for(int i=0; i<nums.size(); i++){
            for(int j=nums[i][0]; j<=nums[i][1]; j++){
                mp[j]++;
            }
        }
        return mp.size();
    }
};
