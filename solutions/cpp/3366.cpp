class Solution {

    //size nums, op1 and op2 are all max 100, we go 101 for base case
    int dp[101][101][101];

    public:
        int minArraySum(vector<int>& nums, int k, int op1, int op2) {
            int n = nums.size();
            //initialize dp, set all elements to -1
            memset(dp, -1, sizeof(dp));
            return solve(nums, 0, k, op1, op2);
        }

        int solve(vector<int>& nums, int i, int k, int op1, int op2){
            //base case
            if(i == nums.size()) return 0;
            if(dp[i][op1][op2] != -1) return dp[i][op1][op2];

            int res_1 = INT_MAX, res_2 = INT_MAX, res_1_2 = INT_MAX, res_2_1 = INT_MAX; 

            //noop case
            int res_none = nums[i] + solve(nums, i+1, k, op1, op2);

            //op1 case
            if(op1){
                res_1 = (nums[i] + 1) / 2 + solve(nums, i + 1, k, op1 - 1, op2);
            }

            //op2 case
            if(op2 && nums[i] >= k){
                res_2 = nums[i] - k + solve(nums, i + 1, k, op1, op2 - 1);
            }

            if(op1 && op2){
                // op1 then op2 case
                int div = (nums[i] + 1) / 2;
                if(div >= k){
                    res_1_2 = div - k + solve(nums, i + 1, k, op1 - 1, op2 - 1);
                }
                // op2 then op1 case 
                if( nums[i] >= k){
                    res_2_1 =  (nums[i] - k + 1) / 2 + solve(nums, i + 1, k, op1 - 1, op2 - 1);
                }
            }

            return dp[i][op1][op2] = min({res_none, res_1, res_2, res_1_2, res_2_1});
        }

};
