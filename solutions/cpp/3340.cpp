class Solution {
public:
    bool isBalanced(string num) {
        int even = 0, odd = 0;
        for(int i=0; i<num.size(); i++){
            int digit = ((int)num[i]) - ((int)'0');
            if(i % 2 == 1) odd += digit;
            else even += digit;
        }
        return even == odd;
    }
};
