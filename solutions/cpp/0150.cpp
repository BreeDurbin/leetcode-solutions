class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& t : tokens){
            if(t == "+"){
                int b = st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a + b);
            }
            else if(t == "-"){
                int b = st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a - b);
            }
            else if(t == "*"){
                int b = st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a * b);
            }
            else if(t == "/"){
                int b = st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a / b);
            }
            else st.push(stoi(t));

        }
        return st.top();
    }
};
