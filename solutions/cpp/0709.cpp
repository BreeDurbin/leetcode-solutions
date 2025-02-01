class Solution {
public:
    string toLowerCase(string s) {
      int m = s.size();
      for(auto & c : s){
        if(c >= 'A' && c <= 'Z'){
            int digit = c - 'A';
            c = 'a' + digit;
        }
      }
      return s;
    }
};
