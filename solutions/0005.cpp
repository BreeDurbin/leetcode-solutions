class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string ans = "";
        int n = s.size();
        
        for(int i=0; i<n; i++){
            // odds
            int dist = 0;
            while(i - dist >= 0 && i + dist < n && s[i - dist] == s[i + dist]){
                if(ans.size() < (2 * dist) + 1) ans = s.substr(i - dist, 2*dist + 1);
                dist++;
            }
            // evens
            int dist2 = 0;
            while(i - dist2 >= 0 && i + dist2 + 1 < n && s[i - dist2] == s[i + dist2 + 1]){
                if(ans.size() < 2 * (dist2 + 1)){
                    ans = s.substr(i - dist2, 2*(dist2 + 1));
                    cout << "HIYA:" << ans << endl;
                }
                dist2++;
            }

        }

        return ans;
    }
};