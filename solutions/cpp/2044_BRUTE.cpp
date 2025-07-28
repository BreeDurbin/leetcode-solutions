class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0, max_OR = 0, n = nums.size();

        for(auto num : nums) max_OR |= num;

        function<void(int, int)> dfs = [&](int i, int cur){
            if(i ==  n){
                ans += cur == max_OR;
                return;
            }

            dfs(i + 1, cur);
            dfs(i + 1, cur | nums[i]);
        };

        dfs(0,0);

        return ans;
    }
};
