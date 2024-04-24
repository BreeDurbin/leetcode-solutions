class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto &num : nums){
            int temp = num, maxDigit=0, count=0;
            while(temp){
                maxDigit = max(maxDigit, temp % 10);
                temp /= 10;
                count++;
            }
            int total = maxDigit;
            for(int i=1; i<count; i++){
                total *= 10;
                total += maxDigit;
            }
            ans += total;
        }
        return ans;
    }
};