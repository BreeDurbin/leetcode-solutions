class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;

        int m = nums.size();

        for(int i=0; i<m-2; i++)
            for(int j = i+1; j < m-1; j++)
                for(int k = j+1; k < m; k++){
                    long long temp = (long long)(nums[i] - nums[j]) * nums[k];
                    if(temp > ans) ans = temp;
                }

        return ans;
    }
};
