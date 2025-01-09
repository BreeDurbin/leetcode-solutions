class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), ans = 0, k = pref.size();

        for(int i=0; i<n; i++){
            if(words[i].substr(0, k) == pref){
                ans++;
            }
        }

        return ans;
    }
};
