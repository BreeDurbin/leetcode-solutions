class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int,int>> cache;

        for(int i=0; i<n; i++){
            if(!cache.count(s[i])) cache[s[i]] = {i, i};
            else cache[s[i]].second = i;
        }

        int ans = 0;
        for(auto [key, val] : cache){
            if(val.first == val.second) continue;
            unordered_set<char> count(s.begin() +  val.first + 1, s.begin() +  val.second);
            ans += count.size();
        }
        
        return ans;
    }
};
