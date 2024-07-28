class Solution {
    public:
        bool isValid(string s) {

            //if(s.size() == 1) return false;
            //if(s[s.size() - 1] == '(' || s[s.size() - 1] == '{' || s[s.size() - 1] == '[') return false;
            //if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;

            std::stack<char> parens_stack;

            for(int i = 0; i < s.size(); i++){
                if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                    parens_stack.push(s[i]);
                } else {
                    if(parens_stack.empty() || parens_map[parens_stack.top()] != s[i]){
                        return false;
                    }
                    parens_stack.pop();
                }
            }

            return parens_stack.empty();
        }

    private:
        unordered_map<char,char> parens_map = {{'(',')'}, {'{','}'}, {'[',']'}};

};