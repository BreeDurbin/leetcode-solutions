class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int sqrt_n = sqrt(right);
        vector<bool> sieve(right+1, true);
        sieve[0] = false;
        sieve[1] = false;

        for(int i=2; i*i<=right; i++){
            if(!sieve[i]) continue; // if crossed out already not prime so skip
            int temp = i;

            while(temp + i <= right){
                temp += i;
                sieve[temp] = false;
            }
        }

        int dist = INT_MAX, prev_index = -1;
        vector<int> ans = {-1,-1};
        for(int i=left; i<=right; i++){
            if(prev_index == -1 && sieve[i]){prev_index = i; continue;}
            if(sieve[i] && i-prev_index < dist){
                ans = {prev_index, i};
                dist = i-prev_index;
                prev_index = i;
            } else if(sieve[i]){
                prev_index = i;
            }
        }

        return ans;
    }
};
