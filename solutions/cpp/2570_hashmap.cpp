class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(), n = nums2.size();

        unordered_map<int,int> mp;

        for(auto pair : nums1) mp[pair[0]] += pair[1];
        for(auto pair : nums2) mp[pair[0]] += pair[1];

        vector<vector<int>> ans;

        for(auto & [id, sum] : mp) ans.push_back({id, sum});

        sort(ans.begin(), ans.end());

        return ans;
    }
};
