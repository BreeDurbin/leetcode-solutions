class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        for(auto& num : nums){
            if(num <= left){
                left = num;
            } else if(num <= mid) {
                mid = num;
            }
            else return true;
        }

        return false;
    }
};