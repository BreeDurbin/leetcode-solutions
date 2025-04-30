class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            if(is_even_digit_size(num)) ans++;
        }
        return ans;
    }
    bool is_even_digit_size(int num){
        int ans = 0;
        while(num > 0){
            ans++;
            num = num / 10;
        }
        return ans % 2 == 0;
    }
};
