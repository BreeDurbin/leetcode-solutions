class Solution {
public:

    int jump(vector<int>& nums) {
        int ans = 0, l = 0, r = 0;

        while(r < nums.size() - 1){
            int dist = 0;
            for(int i=l; i<r+1; i++){
                dist = max(dist, i + nums[i]); 
            }
            l = r + 1;
            r = dist;
            ans++;
        }

        return ans;
    }

};