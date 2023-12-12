class Solution {
public:
    int climbStairs(int n) {
        return climbStairs(0,n);
    }

    int climbStairs(int pos, int n){
        if(pos == n) return 1;
        if(pos > n) return 0;
        if(cache[pos]) return cache[pos];
        int one = climbStairs(pos+1, n);
        int two = climbStairs(pos+2, n);
        cache[pos] = one + two;
        return cache[pos];
    }

private:
    // key: positions value: ways to get to n
    unordered_map<int, int> cache;
};