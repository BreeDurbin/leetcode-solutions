#define ll long long

class Solution {
public:
    ll findKthSmallest(vector<int>& coins, int k) {
        
        ll left = 1, right = 1e11, ans = 0, kk = k;
        
        while(left <= right){
            ll mid = left + (right - left) / 2;
            ll count = 0;
            //coutn the number of coins at the middle point; 
            count = pie(coins, mid);

            if(count < kk) left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        
        return ans;
    }

    ll pie(vector<int>& coins, ll x){
        int m = coins.size();
        int nn = (1 << m);
        ll count = 0;

        for(int i=1; i<nn; i++){
            ll lcmm = 1;
            for(int j=0; j<m; j++){
                if(i & (1 << j)){
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            if(__builtin_popcount(i) & 1) count += x / lcmm;
            else count -= x / lcmm;
        }

        return count;
    }
};