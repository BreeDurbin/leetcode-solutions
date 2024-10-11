class Solution {
public:

    unordered_map<int,int> fibs;

    int fib(int n) {
        if(n == 0) return 0;
        if(n==1) return 1;
        if(fibs.find(n) != fibs.end()) return fibs[n];
        int ans = fib(n-1) + fib(n-2);
        fibs[n] = ans;
        return ans;
    }
};
