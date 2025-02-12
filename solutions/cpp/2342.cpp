class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        int ans = INT_MIN;

        for(auto & num : nums) mp[digit_sum(num)].push(num);

        for(auto [sum, q] : mp){
            if(q.size() > 1){
                int first = q.top(); q.pop();
                int second = q.top(); q.pop();
                ans = max(ans, first + second);
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }

    int digit_sum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
