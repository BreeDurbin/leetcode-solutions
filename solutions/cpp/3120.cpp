class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), ans = 0;
        int chars[52] = {0};
        
        for(int i=0; i<n; i++){
            if(isupper(word[i])) chars[word[i] - 'A' + 26]++;
            else chars[word[i] - 'a' ]++;
        }
        
        for(int i=0; i<26; i++){
            if(chars[i] > 0 && chars[i + 26] > 0) ans++;
        }
        
        return ans;
    }
};