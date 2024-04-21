class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), ans = 0;
        int chars[52] = {0};
        
        for(int i=0; i<n; i++){
            // if lowercase 
            // if the uppercase has appeared set lowercase count to 0
            if(islower(word[i])){
                //check if uppercase version is found
                if(chars[word[i] - 'a' + 26] > 0){
                    //since uppercase exists set lowercase count to 0
                    chars[word[i] - 'a'] = 0;
                } else {
                    chars[word[i] - 'a' ]++;
                }
                continue;
            }
            if(isupper(word[i])){
                chars[word[i] - 'A' + 26]++;
                continue;
            }
        }
        
        for(int i=0; i<26; i++){
            if(chars[i] > 0 && chars[i + 26] > 0) ans++;
        }
        
        return ans;
    }
};