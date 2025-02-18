class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int m = s.size();
        for(int i=0; i+k-1<m; i++){
            for(int j=i; j<=i+k; j++){
                if(s[i] != s[j]) break;
                if(j+1 == i+k){
                    // check edge cases
                    if(i != 0 && s[i] == s[i-1]) break;
                    if(i+k-1 < m && s[i+k-1] == s[i+k]) break;
                    return true;
                }
            }
        }
        return false;
    }
};
