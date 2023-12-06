class Solution {
public:
    int tribonacci(int n) {
        vector<int> memo(n+1,0);
        for(int i = 1; i <= n; i++) memo[i] = 1;

        if(n<3) return memo[n];

        for(int i = 3; i <= n; i++){
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }
        return memo[n];
    }
};