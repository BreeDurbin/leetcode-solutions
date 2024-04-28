class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0, count=0;
        while(count < n){
            ans |= x;
            count++;
            ans++;
        }
        
        return ans - 1;
    }
};