class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum = INT_MAX, n = nums.size();

        for(int i=0; i<n; i++){
            int temp = 0, tempL = 0;
            for(int j=i; j<r+i && j<n; j++){
                temp += nums[j];
                tempL++;
                if(tempL >= l && tempL<= r && temp > 0){
                    //cout << "j " << j << " temp " << temp << " numsj " << nums[j] << endl;
                    sum = min(temp, sum);
                }
            }
        }

        return sum == INT_MAX ? -1 : sum;
    }
};
