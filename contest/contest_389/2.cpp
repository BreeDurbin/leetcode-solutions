class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.size();
        long long ans = 0;
        int c_count = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == c){
                c_count++;
                ans += c_count;
            }
        }
        
        return ans;
    }
};