class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int chunkSize = n / k;
        unordered_map<string,int> m;
        
        for(int i=0; i<n; i+=chunkSize){
            m[s.substr(i, chunkSize)]++;
            m[t.substr(i, chunkSize)]--;
        }

        for(auto & [key, val] : m){
            if(val != 0) return false;
        }

        return true;
    }
};
