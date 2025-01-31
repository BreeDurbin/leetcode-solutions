class Solution {
public:
    int strStr(string str, string pattern) {
        int m = str.size(), k = pattern.size();
        vector<int> pi = lps(pattern);

        int str_index = 0, pattern_index = 0;
        while(str_index < m && pattern_index < k){
            if(str[str_index] == pattern[pattern_index]){
                str_index++;
                pattern_index++;
            }
            else if(pattern_index != 0){
                pattern_index = pi[pattern_index - 1];
            }
            else str_index++;
        }

        return pattern_index == k ? str_index - pattern_index : -1;
    }

    vector<int> lps(string s){ // longest prefix which is the same as some suffix
        int m = s.size();
        vector<int> pi(m);

        int prefix = 0, suffix = 1;
        while(suffix < m){
            if(s[prefix] == s[suffix]){
                ++prefix;
                pi[suffix] = prefix;
                ++suffix;
            }
            else if(prefix == 0){
                pi[suffix] = 0;
                suffix++;
            }
            else{
                prefix = pi[prefix-1];
            }
        }

        return pi;
    }
};
