class Solution {
public:

    string decodeString(string s) {
        cout << s << endl;
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(const string& s, int& i){
        string ans;

        while(i < s.length() && s[i] != ']'){
            //if we are in a char -> [stuff]
            if(!isdigit(s[i])){
                ans += s[i++];
            }
            else {
                // eat the int. nomnomnom
                int startOfInt = i;
                while(s[i] != '['){
                    i++;
                }
                // How many times we'e gonna repeat the string we're about to nom nom
                string substr = s.substr(startOfInt, i - startOfInt);
                int count = stoi(substr);


                i++;// skip '['
                //nom nom handles any nested encoding inside []
                string decoded = decodeString(s, i);
                i++; // skip "]"

                // append substr count # of times to ans.
                while(count > 0){
                    ans += decoded;
                    count--;
                }
                cout << " hiya ans so far is " << ans << " s[i] " << s[i] << endl;
            }
        }

        return ans;
    }
};