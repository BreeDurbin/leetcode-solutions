class Solution {
public:
    int maximumLength(string s) {
        int ans = -1, n = s.size();
        unordered_map<string, int> m;

        for(int i=0; i<n; i++){
            string cur;
            for(int j=i; j<n; j++){
                if(cur.empty() || cur.back() == s[j]){
                    cur.push_back(s[j]);
                    m[cur]++;
                } else break;
            }
        }

        for(auto &[str, count] : m){
            if(count >= 3) ans = max(ans, (int)str.size());
        }

        return ans;        
    }
};
