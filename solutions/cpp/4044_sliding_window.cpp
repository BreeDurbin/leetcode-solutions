class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        long long left_sum = 0;
        long long total = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            total += nums[i];
        }

        for(int i=0; i<n/2; i++){
            left_sum += nums[i];
        }

        for(int i=0; i<n; i++){
            long long right_sum = total - left_sum;
            if(left_sum > right_sum){
                count++;
            }
            left_sum -= nums[i];
            left_sum += nums[(mid + i) % n];
        }

        return count;
    }
};
