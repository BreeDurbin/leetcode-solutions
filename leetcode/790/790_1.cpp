class Solution {
public:
    const long mod = 1e9+7;
    int numTilings(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        long prev3 = 1;
        long prev2 = 2;
        long prev1 = 5;
        long curr = 0;
        for(int i=0; i<n-3; i++){
            curr=((2*prev1) % mod + prev3 % mod);
            prev3=prev2;
            prev2=prev1;
            prev1=curr; 
        }
        return (int)curr % mod;
    }
};