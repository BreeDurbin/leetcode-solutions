class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0;
        for(auto c : s) if(c == '1') ones++;
        
        int ans = 0, zeroes = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] == '0') zeroes++;
            if(s[i] == '1') ones--;
            ans = max(ans, zeroes + ones);
        }

        return ans;
    }
};
