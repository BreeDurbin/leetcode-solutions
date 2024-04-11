class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v(n);
        for(int i=0; i < n; i++){
            v[i] = to_string(i+1);
        }

        while(v.size() > 1){
            for(int l=0, r=v.size()-1; l<r; l++, r--){
                v[l] = "(" + v[l] + ',' + v[r] + ")";
            }
            v.resize(v.size()/2);
        }
        
        return  v[0];
    }
};