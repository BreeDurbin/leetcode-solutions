class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0;
        int digit_product = 1;

        int k = n;

        while(k){
            int digit = k % 10;
            k /= 10;

            digit_sum += digit;
            digit_product *= digit;
        }

        return n % (digit_sum + digit_product) == 0;
    }
};
