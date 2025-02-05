class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int m = accounts.size(), n = accounts[0].size();
       int ans = 0;
       for(auto customer : accounts){
        int cur = 0;
        for(auto account : customer) cur += account;
        ans = max(ans, cur);
       }

       return ans;
    }
};
