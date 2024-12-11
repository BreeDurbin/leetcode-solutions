class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, twok = 2*k;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int count = 0;
            int j = binarySearch(nums, nums[i] + 2*k);
            ans = max(ans, j - i + 1);
        }

        return ans;
    }

    int binarySearch(vector<int>& nums, int i){
        int left = 0, right = nums.size() - 1, ans = 0;

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] <= i){
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
