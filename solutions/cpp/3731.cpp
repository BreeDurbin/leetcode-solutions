class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.size() <= 1) return {}; 
        sort(nums.begin(), nums.end());
        unordered_set<int> num_set;

        for(auto num : nums) num_set.insert(num);

        vector<int> ans;

        for(int i=nums[0]; i<nums[nums.size() - 1]; i++){
            if(!num_set.contains(i)) ans.push_back(i);
        }


        return ans;

    }
};
