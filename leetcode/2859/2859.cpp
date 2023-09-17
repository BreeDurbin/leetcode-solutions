class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        vector<int> total_binary_digits(nums.size());
        for(int i=0; i<nums.size(); i++){
            int temp = i;
            while(temp>0){
                int digit=temp%2;
                if(digit == 1){
                    total_binary_digits[i]++;
                }
                temp/=2;
            }
        }
        
        int total=0;
        for(int i=0; i<total_binary_digits.size();i++){
            //cout << "i: " << i << " total_binary_digits[i]: " << total_binary_digits[i] << endl;
            if(total_binary_digits[i]==k){
                total += nums[i];
            }
        }
        
        return total;
    }
};