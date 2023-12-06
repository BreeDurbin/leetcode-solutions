class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int* min = &prices[0];
        int currentMaxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(*min > prices[i]) min = &prices[i];
            else currentMaxProfit = prices[i] - *min;
            if(maxProfit < currentMaxProfit) maxProfit = currentMaxProfit;
        }
        return maxProfit;
    }
};