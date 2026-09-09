class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;

        if(n >= 1000){
            count += n - 999;
        }

        if(n >= 1'000'000){
            count += n - 999'999;
        }

        if(n >= 1'000'000'000){
            count += n - 999'999'999;
        }

        if(n >= 1'000'000'000'000){
            count += n - 999'999'999'999;
        }

        if(n >= 1'000'000'000'000'000){
            count += n - 999'999'999'999'999;
        }


        return count;
    }
};
