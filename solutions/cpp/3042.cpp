class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
    int ans = 0, n = words.size();

    for(int j=0; j<n; j++){
        for(int i=0; i < j; i++){
            if(isPrefixAndSuffix(words[i], words[j])) ans++;
        }
    }

    return ans;
    }

    bool isPrefixAndSuffix(string& p, string& s){
        if(p.size() > s.size()) return false;
        for(int i=0; i<p.size(); i++){
            if(p[i] != s[i] || p[i] != s[s.size() - p.size() + i]) return false;
        }
        return true;
    } 
};
