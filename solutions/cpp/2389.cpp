class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ret;
        
        for(int & q : queries){
            int cur_sum = 0, i = 0;
            while(cur_sum <= q && i<n){
                if(cur_sum + nums[i] <= q){
                    cur_sum += nums[i];
                    ++i;
                } else break;
            }
            ret.push_back(i);
        }
        return ret;
    }
};
