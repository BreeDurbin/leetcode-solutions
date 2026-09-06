class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        int mid = (n - 1) / 2;
        int prefix_mid = mid + 1;

        int count = 0;

        vector<long> prefix_sum(n + 1, 0);

        // Normal prefix sum
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        int total = prefix_sum[n];

        // Extended prefix sum
        for (int i = 1; i <= n; i++) {
            prefix_sum.push_back(total + prefix_sum[i]);
        }

        for (int i = 0; i < n; i++) {
            int prefix_left_end = prefix_mid + i;

            long left_sum = prefix_sum[prefix_left_end] - prefix_sum[i];
            long right_sum = total - left_sum;

            if (left_sum > right_sum) {
                count++;
            }
        }

        return count;
    }
};
