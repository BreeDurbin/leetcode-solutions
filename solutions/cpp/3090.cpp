class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans=0;

        for(int i=0; i<n-1; i++){
            unordered_map<char, int> count;
            for(int j=i; j<n; j++){
                count[s[j]]++;
                if(count[s[j]] == 3){
                    break;
                } else{
                    ans = max(j-i+1, ans);
                }
            }
        }
        
        return ans;
    }
};