class Solution {
public:
    int arrangeCoins(int n) {
        int k=1;
        long total = 1;
        while(total<=n){
            ++k;
            total = ((long)k*(k+1))/2;
        }
        return k-1;
    }
};
