class Solution {
public:

    int calculate(string s) {
        stack<int> st;
        int operand = 0;
        int result = 0;
        int sign = 1;

        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(isdigit(c)) operand = 10 * operand + (int) (c - '0');
            else if(c == '+'){
                result += sign * operand;
                sign = 1;
                operand = 0;
            } 
            else if(c == '-'){
                result += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if(c == '('){
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            else if(c == ')'){
                result += sign * operand;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                operand = 0;
            }
        }
        return result + (sign * operand);
    }

};
