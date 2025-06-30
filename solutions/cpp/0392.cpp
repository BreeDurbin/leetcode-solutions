class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0, right = 0;

        while(left < s.size() && right < t.size()){
            if(s[left] == t[right++]) left++;
        }
        
        return left == s.size();
    }
};
