class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> primes_count;

        int ans = 0;

        for(int left = 0, right = 0; right < nums.size(); right++){

            // add primes
            auto primes = get_primes(nums[right]);
            for(auto prime : primes) primes_count[prime]++;

            while(primes_count.size() > k){
                auto primes = get_primes(nums[left]);
                for(auto prime : primes){
                    primes_count[prime]--;
                    if(primes_count[prime] == 0) primes_count.erase(prime);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }


    vector<int> get_primes(int num){
        vector<int> primes;
        for(int i=2; i*i <= num; i++){
            if(num%i == 0){
                primes.push_back(i);
            }
            while(num % i == 0){
                num /= i;
            }
        }

        if(num > 1) primes.push_back(num);

        return primes;
    }
};
