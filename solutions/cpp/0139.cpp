class Solution {
public:

    bool wordBreak(string s, vector<string>& words) {
        vector<bool> dp(s.size());
        bool ans = false;

        for(int i=0; i<s.length(); i++){
            for(auto & word : words){
                if(i < word.length() - 1) continue;
                if(i == word.length() - 1 || dp[i - word.length()]){
                    if(s.substr(i - word.length() + 1, word.length()) == word){
                        dp[i] = true;
                        break;
                    }
                }
            }

        }

        return dp[s.length()-1];
    }
};
