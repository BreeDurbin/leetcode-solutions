class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, m = nums1.size(), n = nums2.size();
        if(m%2==1) for(int i=0; i<n; i++) ans ^= nums2[i];
        if(n%2==1) for(int i=0; i<m; i++) ans ^= nums1[i];
        return ans;
    }
};
