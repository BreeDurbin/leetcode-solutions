class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<bool> seen(nums.size(), false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        for(int i = 0; i<nums.size(); i++){
            q.push({nums[i], i});
        }

        while(!q.empty()){
            auto t = q.top();
            q.pop();
            if(seen[t[1]]) continue;
            score += t[0];
            seen[t[1]] = true;
            if(t[1] - 1 >= 0) seen[t[1] - 1] = true;
            if(t[1] + 1 < nums.size()) seen[t[1] + 1] = true;
        }

        return score;
    }
};
