class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            pre[i] = nums[i] + pre[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suf[i] = nums[i] + suf[i+1];
        }

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                int diff = abs(pre[i] - suf[i]);
                //cout << "diff " << diff << " i " << i << " pre " << pre[i] << " suf " << suf[i] << endl;
                if(diff == 1) ans++;
                if(diff == 0) ans += 2;
            }
        }


        return ans;
    }
};
