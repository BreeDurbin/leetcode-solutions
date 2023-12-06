class Solution {
public:
    string reverseWords(string s) {
        
        int start = 0, end = s.size() - 1;

        string temp = "";
        stack<string> stack;
        int i = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == ' '){
                if(temp != "") stack.push(temp);
                temp = "";
            }
            else {
                temp += ch;
            }
        }

        if(temp != ""){
            stack.push(temp);
        }
        string ans = "";

        while(!stack.empty()){
            ans +=(stack.top() + " ");
            stack.pop();
        }
        ans.pop_back();

        return ans;
    }
};