class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> lefts({'(', '[', '{'});
        stack<char> st;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(lefts.count(s[i])){
                st.push(s[i]);
                continue;
            }
            else if (!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if (!st.empty() && st.top() == '[' && s[i] == ']'){
                st.pop();
            }
            else if (!st.empty() && st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else return false;

        }

        return st.empty();
        
    }
};
