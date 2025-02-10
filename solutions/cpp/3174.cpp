class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<bool> remove(n, false);
        stack<int> st;

        for(int i=0; i<n; i++){
            if(!isdigit(s[i])){
                st.push(i);
            }
            if(isdigit(s[i])){
                remove[i] = true;
                if(!st.empty()){
                    remove[st.top()] = true;
                    st.pop();
                }
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(!remove[i]) ans += s[i];
        }

        return ans;
    }
};
