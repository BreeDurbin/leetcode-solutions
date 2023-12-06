class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), ans=0;
        if(left==h) return right;

        while(left<=right){
            int mid = left + (right - left) / 2;
            long time_to_eat = 0;
            for(int i=0; i<piles.size(); i++){
                time_to_eat += ceil(piles[i]/(double)mid);
            }

            //can eat all
            if(time_to_eat<=h){
                right = mid-1;
                ans=mid;
            } else {
                left = mid+1;
            }

        }
        return ans;
    }
};