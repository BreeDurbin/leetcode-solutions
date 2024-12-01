
class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        
        while(n){
            n /= 2;
            ans *=2;
        }

        return ans - 1;
    }
};
