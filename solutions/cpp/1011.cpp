class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;

        for(auto & w : weights){
            right += w;
            left = max(left, w);
        }

        while(left < right){
            int mid = (left + right) / 2;
            if(possible(weights, days, mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool possible(vector<int>& weights, int days, int capacity){
        int weightSum = 0, daysPassed = 1;
        for(auto & w : weights){
            if(w > capacity) return false;
            if(w + weightSum > capacity){
                daysPassed++;
                weightSum = 0;
            }
            weightSum += w;
        }

        return daysPassed <= days;
    }
};
