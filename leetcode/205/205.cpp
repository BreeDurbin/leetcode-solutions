class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> forward,backward;
        for(int i=0;i<s.size();i++){
            if((forward[s[i]] && forward[s[i]]!=t[i]) 
                || (backward[t[i]] && backward[t[i]]!=s[i])) return false;
            forward[s[i]]=t[i];
            backward[t[i]]=s[i];
        }
        return true;
    }
};