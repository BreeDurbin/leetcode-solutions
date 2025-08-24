class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i=1; i<=2*n-1; i+=2){
            odd += i;
        }
        for(int i=2; i<=2*n; i+=2){
            even += i;
        }

        return gcd(odd, even);
    }

    int gcd(int a, int b){
        return _gcd(max(a,b), min(a,b));
    }

    int _gcd(int bigger, int smaller){
        if(smaller == 0) return bigger;
        return _gcd(smaller, bigger%smaller);
    }
};
