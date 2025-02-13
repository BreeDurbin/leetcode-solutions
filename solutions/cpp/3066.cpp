class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> q;
        int ans = 0;

        for(auto num : nums) q.push(num);
        while(q.size() > 1 && q.top() < k){
            long first = q.top(); q.pop();
            long second = q.top(); q.pop();
            q.push(2 * first + second);
            ans++;
        }

        return ans;

    }
};
