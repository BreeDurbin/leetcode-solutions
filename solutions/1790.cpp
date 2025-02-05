class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        
        if(m != n) return false;
        if(s1 == s2) return true;

        priority_queue<int> q;
        for(int i=0; i<m; i++){
            if(s2[i] != s1[i]) q.push(i);
        }

        if(q.size() != 2) return false;

        int i = q.top(); q.pop();
        int j = q.top(); q.pop();

        unordered_set<char> set_1;
        set_1.insert(s1[i]);
        set_1.insert(s1[j]);

        return (set_1.find(s2[i]) != set_1.end()) && (set_1.find(s2[j]) != set_1.end());
    }
};
