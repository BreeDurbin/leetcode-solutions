class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;

        bool startCount = false;
        for(int i = s.size() - 1; i >= 0; i--){
            if(!startCount && s[i] != ' ') startCount = true;
            if(startCount){
                if(s[i] != ' ') ret++;
                else break;
            }
        }
        return ret;
    }
};