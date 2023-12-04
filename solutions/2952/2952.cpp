class Solution {
public:

    int minimumAddedCoins(vector<int>& coins, int target) {
        int ans = 0, sum = 0;
        sort(coins.begin(), coins.end());
        
        for(auto &coin : coins){
            if(sum >= target) break;
            while(coin > sum+1 && sum < target){
                ans++;
                sum += sum + 1;
            }
            sum += coin;
        }
        
        while(sum < target){
            ans++;
            sum += sum + 1;
        }
        
        return ans;
    }

};