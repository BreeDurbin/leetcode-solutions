class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int forward[256]={0},backward[256]={0}, n=s.size();
        for(int i=0;i<n;++i){
            if(forward[s[i]]!=backward[t[i]]) return false;
            forward[s[i]]=i+1;
            backward[t[i]]=i+1;
        }
        return true;
    }
};