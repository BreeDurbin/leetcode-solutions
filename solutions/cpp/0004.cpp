class Solution {
public:
    double findMedianSortedArrays(vector<int>& small, vector<int>& big) {
        int m = small.size(), n = big.size();
        int length = m + n;

        //force first array to be the smaller one if it isnt
        if(m > n) return findMedianSortedArrays(big, small);

        int left = 0, right = m;

        while(left <= right){
            int mid1 = (left + right) / 2;
            int mid2 = (length + 1) / 2 - mid1;

            //initialize 
            int maxLeftSmall = mid1 == 0 ? INT_MIN : small[mid1 - 1];
            int minRightSmall = mid1 == m ? INT_MAX : small[mid1];
            int maxLeftBig =  mid2 == 0 ? INT_MIN : big[mid2 - 1];
            int minRightBig = mid2 == n ? INT_MAX : big[mid2];

            //median case
            if(maxLeftSmall <= minRightBig && maxLeftBig <= minRightSmall){
                if(length % 2 == 0) return (double)(max(maxLeftSmall, maxLeftBig) + min(minRightSmall, minRightBig)) / 2;
                else return (double)max(maxLeftSmall, maxLeftBig);
            } 
            //shrink left side case
            else if (maxLeftSmall > minRightBig){
                right = mid1 - 1;
            }
            //shrink right side case
            else{
                left = mid1 + 1;
            }
        }

        return 0;
    }

};
