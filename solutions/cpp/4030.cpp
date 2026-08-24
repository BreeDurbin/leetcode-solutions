class Solution {
public:
    bool isPalindromic(string s) {

        string binary_string;
        
        for(int i=0; i<s.size(); i++){
            binary_string += to_binary_str(s[i]);
        }

        return is_palindrome(binary_string);

    }

    bool is_palindrome(string s){
        for(int i = 0; i<s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]) return false;
        }

        return true;
    }

    string to_binary_str(char c){
        // input is 8 bit ascii char
        string s = "";

        int ascii = c;
        
        for(int i=0; i<8; i++){
            if(ascii % 2 == 1){
                s += '1';
            }
            else {
                s += '0';
            }

            ascii /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};
