class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0, temp = 0;
        for(int i=0; i<32; i++){
            temp = (n >> i) & 1;
            ans = ans | (temp << (31 - i));
        }
        return ans;
    }
};