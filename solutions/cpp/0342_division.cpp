class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        if(n == 1) return true;

        int i = n;
        while(i > 1){
            if(i % 4 != 0) return false;
            i /= 4;
        }

        return i == 1;
    }
};
