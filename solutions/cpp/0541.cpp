class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        
        for(int i=0; i < n; i+=2*k){
            if(i+k >= n){
                reverse(s.begin() + i, s.begin() + n);
            } else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};