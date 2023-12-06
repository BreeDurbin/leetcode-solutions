class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0, i = 0, j = 0;

        while(j < t.size()){
            if(s[count]==t[j++]){
                count++;
            }
        }

        return count == s.size();
    }
};