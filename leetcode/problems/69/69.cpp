class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;

        int end = x;
        int start = 1;
        long midSq = 0;
        int mid = -1;

        while(start <= end){
            mid = start + (end - start) / 2;
            long long midSq = static_cast<long long>(mid) * mid;
            if(midSq < x){
                start = mid + 1;
            } else if (midSq > x){
                end = mid - 1;
            } else {
                return mid;
            }
        }

        return static_cast<int>(std::round(end));
        
    }

};
    
