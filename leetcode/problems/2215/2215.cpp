class Solution {
    unordered_set<int> nums1Set;
    unordered_set<int> nums2Set;
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        for(auto& num : nums1){
            nums1Set.insert(num);
        }
        for(auto& num : nums2){
            nums2Set.insert(num);
        }
        vector<int> nums1Distinct, nums2Distinct;

        for(auto& num : nums1Set){
            if(nums2Set.find(num) == nums2Set.end()) nums1Distinct.push_back(num);
        }
        for(auto& num : nums2Set){
            if(nums1Set.find(num) == nums1Set.end()) nums2Distinct.push_back(num);
        }
        vector<vector<int>> ans{ nums1Distinct, nums2Distinct };
        return ans;
    }
};