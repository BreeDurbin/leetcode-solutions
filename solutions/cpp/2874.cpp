class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        vector<int> maxi, maxk;
        maxi.push_back(nums[0]);
        maxk.push_back(nums[n-1]);
        for(int i=1; i<n; i++){
            maxi.push_back(max(nums[i],maxi[i-1]));
            maxk.push_back(max(nums[n-i-1],maxk[i-1]));
        }
        reverse(maxk.begin(),maxk.end());
        for(int j=1; j<n-1; j++){
            long long temp = (long long)(maxi[j-1]-nums[j])*maxk[(j+1)];
            ans=max(temp, ans);
        }
        return ans;
    }
};