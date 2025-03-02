class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int m = nums.size(), ans = -1;
        if(k > m) return -1;
        unordered_map<int,int> f;

        for(int i=0; i+k-1<m; i++){
            //subarray from i to i+k
            unordered_set<int> s;
            for(int j = 0; j<k; j++){
                s.insert(nums[i+j]);
            }
            for(auto num : s){
                f[num]++;
            }
        }

        for(auto & [num, freq] : f) if(freq == 1) ans = max(ans, num);

        return ans;
    }
};
