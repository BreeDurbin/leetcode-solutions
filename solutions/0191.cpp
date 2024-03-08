class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamming = 0;
        while(n > 0){
            if(n%2 == 1) hamming++;
            n /= 2;
        }
        return hamming;
    }
};