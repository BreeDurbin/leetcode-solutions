class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);

        int ans{0};
        for(int i=0; i<n; i++){
            ans = max(ans, 1 + dfs(i, d, arr, memo));
        }
        return ans;
    }

    int dfs(int i, int d, vector<int>& arr, vector<int>& memo){
        if(memo[i] != -1) return memo[i];
        memo[i] = 0;

        int jump = i - 1;
        while(jump >= 0 && jump >= i - d && arr[jump] < arr[i]){
            memo[i] = max(memo[i], 1 + dfs(jump, d, arr, memo));
            jump--;
        }

        jump = i + 1;
        while(jump < arr.size() && jump <= i + d && arr[jump] < arr[i]){
            memo[i] = max(memo[i], 1 + dfs(jump, d, arr, memo));
            jump++;
        }

        return memo[i];
    }
};
