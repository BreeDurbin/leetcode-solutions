class Solution {
public:
    int possibleStringCount(string w) {
        int n = w.size(), ans = w.size();
        for(int i=1; i<n; i++) if(w[i] != w[i-1]) ans--;
        return ans;
    }
};
