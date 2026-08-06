class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n; i<INT_MAX; i++){
            int num = i;
            long long product = 1;
            while(num){
                int digit = num % 10;
                num /= 10;

                product *= digit; 
            }
            if(product % t == 0) return i;
        }

        return -1;
    }
};
