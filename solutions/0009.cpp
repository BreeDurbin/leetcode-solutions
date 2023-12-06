class Solution {
public:
    bool isPalindrome(int x) {

        bool truthiness = true;

        auto hiya = to_string(x);
        auto hiyaSizeMinusOne = hiya.size() - 1;

        for(int i = 0; i < hiya.size(); i++){
            if(hiya[i] != hiya[hiyaSizeMinusOne - i]){
                truthiness = false;
                break;
            }
        }
        return truthiness;
    }
};