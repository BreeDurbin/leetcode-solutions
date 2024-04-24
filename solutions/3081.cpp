class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        int freq[26] = {0};
        for(auto &c : s){
            if(c == '?') continue;
            freq[c-'a']++;
        }

        vector<char> buffer;
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                int freqi = INT_MAX, index = 0;
                for(int c='a'; c<='z'; c++){
                    if(freq[c - 'a'] < freqi){
                        index = c - 'a';
                        freqi = freq[c - 'a'];
                    }
                }
                buffer.push_back(index + 'a');
                freq[index]++;
            }
        }
        sort(buffer.begin(), buffer.end());
        for(int i=0, counter=0; i<n; i++){
            if(s[i]=='?') s[i] = buffer[counter++];
        }

        return s;
    }
};