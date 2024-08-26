class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=1;
        while(i<=num){
            long square = i*i;
            if(square == num) return true;
            ++i;
        }
        return false;
    }
};
