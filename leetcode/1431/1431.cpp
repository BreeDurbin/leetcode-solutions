class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        std::vector<bool> res(candies.size());
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] > max) max = candies[i];
        }
        for(int i = 0; i < candies.size(); i++){
            res[i] = (candies[i] + extraCandies) >= max;
        }
        return res;
    }
};