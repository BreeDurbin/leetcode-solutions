class Solution {
    const int MOD = 1'000'000'000 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for(auto query : queries){
            int index = query[0];
            while(index <= query[1]){
                nums[index] = ((long)nums[index] * query[3]) % MOD;
                index += query[2];
            }
        }

        int ans = 0;
        for(auto num : nums){
            ans = ans ^ num;
        }


        return ans;
        
    }
};
