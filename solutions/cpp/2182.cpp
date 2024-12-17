class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        int freq[26];
        int count = 0;
        for(char c : s) freq[c - 'a']++;

        priority_queue<char> q;

        for(int i=0; i<26; i++){
            if(freq[i]) q.push('a' + i);
        }

        while(!q.empty()){
            auto c = q.top();
            q.pop();
            //gredy append as many copies as possible of c up to the repeatLimit
            int count = min(freq[c-'a'], repeatLimit);
            ans.append(count, c);
            freq[c-'a'] -= count;

            //handle if there are extra c left
            if(freq[c - 'a'] && !q.empty()){
                auto temp = q.top();
                q.pop();

                ans += temp;
                freq[temp - 'a']--;

                if(freq[temp - 'a']) q.push(temp);

                q.push(c);
            }

        }


        return ans;
    }
};
