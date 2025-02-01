class Solution {
public:
    int lengthOfLastWord(string s) {
        int m = s.size()-1, len = 0;
        while(m >= 0 && s[m] == ' '){
            m--;// get rid of spaces
        }
        while(m >= 0 && s[m] != ' '){
            m--;
            len++;
        }
        return len;
    }
};
