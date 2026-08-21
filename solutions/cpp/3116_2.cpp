class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int min_coin = *min_element(coins.begin(), coins.end());
        long long left = 0, right = 1LL * k * min_coin;

        return binary_search(left, right, coins, k);
    }

    long long binary_search(long long left, long long right, vector<int>& coins, int k){

        while(left < right){
            long long mid = left + (right - left) / 2;

            long long count = getCount(mid, coins);

            if(count >= k) right = mid;
            else left = mid + 1; 
        }

        return right;
    }


    long long getCount(long long num, vector<int>& coins){
        long long ans = 0;

        for(int mask = 1; mask <= (1 << coins.size()) - 1; mask++){
            
            long long LCM = 1;
            for(int shift=0; shift<coins.size(); shift++){
                if(mask & (1 << shift)) 
                    LCM = lcm(LCM, coins[shift]); 
            }

            if(__builtin_popcount(mask) & 1)  ans += num / LCM;
            else ans -= num / LCM;
        }

        return ans;
    }

};
