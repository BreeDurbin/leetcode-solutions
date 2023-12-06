class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0) nums1 = nums2;
        int i = m - 1, j = n - 1, end = m + n - 1;

        while(j >= 0){
            if( i >= 0 && nums1[i] >= nums2[j]){
                nums1[end--] = nums1[i--];
            } else {
                nums1[end--] = nums2[j--];
            } 
        }
    }
};