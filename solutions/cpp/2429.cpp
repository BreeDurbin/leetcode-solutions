class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits1 = __builtin_popcount(num1);
        int bits2 = __builtin_popcount(num2);
        int ans = num1;

        for(int i = 0; i < 32; ++i){
            if(bits1 > bits2 && (1 << i) & num1){
                ans ^= 1 << i;
                --bits1;
            }
            if(bits1 < bits2 && !((1 << i) & num1)){
                ans ^= 1 << i;
                ++bits1;
            }
        }

        return ans;
    }
};
