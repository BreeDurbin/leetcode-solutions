class Solution {
public:
    bool canChange(string s1, string s2) {
        int p1=0, p2=0, m = s1.size();

        while(p1 < m || p2 < m){
            while(p1 < m && s1[p1] == '_') p1++;
            while(p2 < m && s2[p2] == '_') p2++;
            if(p1 == m || p2 == m) break;
            if(s1[p1] != s2[p2]) return false;
            if(s1[p1] == 'L' && p1 < p2) return false;
            if(s1[p1] == 'R' && p1 > p2) return false;
            p1++; p2++;
        }

        return p1 == m && p2  == m;
    }
};
