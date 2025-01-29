class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m1, m2;
        for(auto c : s) m1[c]++;
        for(auto c : t) m2[c]++;
        for(auto [key, val] : m2) if(m1[key] != m2[key]) return key;
        return ' ';
    }
};
