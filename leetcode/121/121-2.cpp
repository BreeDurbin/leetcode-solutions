class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = prices[0], profit=0;
        for(auto& sell : prices){
            if(buy<sell){
               profit = max(profit, sell-buy); 
            }
            else{
                buy = sell;
            }
        }
        
        return profit;
    }
}; 