class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int steps = n / 3;
        long long ans = 0;

        for(int i=0; i<steps; i++){
            int index = n - 2 - (2*i);
            int temp = nums[index];
            //cout << "median " << temp << endl;
            ans += nums[index];
        }

        return ans;
    }
};
