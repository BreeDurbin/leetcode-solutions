class Solution {
public:
    string findLatestTime(string s) {
        
        int hours = 0, minutes = 0;
        sscanf(s.c_str(), "%d:%di",&hours,&minutes);

        if(s[0] == '?'){
            if(s[1]=='1' || s[1] == '0' || s[1] == '?') s[0] = '1';
            else s[0] = '0';
        }
        if(s[1] == '?'){
            //cout << "hiya" << endl;
            if(s[0] == '?' || s[0] == '1'){
                //cout << "hiya1" << endl;
                s[1] = '1';
            }
            else {
                //cout << "hiya2" << endl;
                s[1] = '9';
            }
        }
        if(s[3] == '?') s[3] = '5';
        if(s[4] == '?') s[4] = '9';
        return s;
    }
};