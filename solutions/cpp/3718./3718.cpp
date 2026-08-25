class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> num_set;

        for(auto num : nums){
            num_set.insert(num);
        }

        int multiple = k;
        while(num_set.contains(multiple)){
            multiple += k;
        }

        return multiple;
    }
};
