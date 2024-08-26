class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto & t : nums){
            if(t < 0){
                neg++;
                continue;
            } if(t > 0){
                pos++;
                continue;
            }
        }
        return max(pos,neg);
    }
};
