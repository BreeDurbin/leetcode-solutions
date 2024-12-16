class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for(int i=0; i<nums.size(); i++){
            q.emplace(nums[i], i);
        }

        while(k--){
            auto [val, key] = q.top();
            q.pop();
            q.emplace(multiplier * val, key);
        }

        while(!q.empty()){
            auto [val, key] = q.top();
            q.pop();
            nums[key] = val;
        }

        return nums;
    }
};
