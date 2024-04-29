class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(int i=0; i<3; i++){
            int temp = nums2[0] - nums1[i];
            if(isValid(nums1, nums2, temp)) ans = min(ans, temp);
        }

        return ans;
    }

    bool isValid(vector<int>& nums1, vector<int>& nums2, int target){
        int count = 0, j=0;
        for(int i=0; i<nums1.size() && j < nums2.size(); i++){
            if(nums1[i] + target != nums2[j]) count++;
            else j++;
        }
        return count > 2 ? 0 : 1;
    }
};