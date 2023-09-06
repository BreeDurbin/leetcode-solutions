class Solution {
public:
    int reverse(int x) {

        if(x > 21474847412 || x < -21474847412) return 0;
        int reversed = 0;
        int digitIndex = 0;

        while(x != 0){
            if(reversed > INT_MAX / 10 || reversed < INT_MIN/10) return 0;
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return reversed;
    }
};