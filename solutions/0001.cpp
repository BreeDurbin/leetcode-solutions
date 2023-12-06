class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int tempTarget = target - nums[i];
            if(map.count(tempTarget) && map[tempTarget] != i){
                return {i, map[tempTarget]};
            } else {
                map[nums[i]] = i;
            }
        }

        return {0, 0};
    }
};