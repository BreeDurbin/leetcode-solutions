class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        
        //cout << "s: " << s << " r " << r << endl;
        
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                //cout << "s substr " << s.substr(i-1, 2) << " r substr " << r.substr(j-1, 2) << endl;
                if(s.substr(i-1, 2) == r.substr(j-1, 2)) return true;
            }
        }
        
        return false;
    }
};