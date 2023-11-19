class Solution {
public:
    double myPow(double x, int n) {
        return kaPow(x, (long long) n);
    }

private:

  double kaPow(double x, long long n){
      if(n == 0) return 1.0;
      if(n < 0) return 1.0 / kaPow(x, -1 * n);
      if(n % 2 == 1) return x * kaPow(x*x, n / 2);
      return kaPow(x*x, n / 2);
  }

};