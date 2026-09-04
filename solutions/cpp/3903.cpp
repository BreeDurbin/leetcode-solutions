class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> max_prefix(n, 0), min_suffix(n, 0);
        max_prefix[0] = nums[0];
        min_suffix[n-1] = nums[n-1];
        // seed prefix and suffix arrays
        for(int i=1; i<n; i++){
            max_prefix[i] = max(nums[i], max_prefix[i-1]);
            min_suffix[n - 1 - i] = min(nums[n - 1 - i], min_suffix[n - 1 - i + 1]);
        }

        // An index i is called stable if its instability score is less than or equal to k.
        // return smallest stable index otherwise return -1;

        //find smallest stable index
        for(int i=0; i<n; i++){
            if(max_prefix[i] - min_suffix[i] <= k){
                return i;
            }
        }

        return -1;
    }
};
