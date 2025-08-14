class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int max_digit = -1;

        for(int i=2; i<n; i++){
            char digit = num[i];
            if(digit == num[i-1] && digit == num[i-2]){
                max_digit = max(max_digit, digit - '0');
            }
        }

        if(max_digit == -1) return "";
        
        string ans = "";
        ans += (char)('0' + max_digit);
        ans += (char)('0' + max_digit);
        ans += (char)('0' + max_digit);

        return ans;
    }
};
