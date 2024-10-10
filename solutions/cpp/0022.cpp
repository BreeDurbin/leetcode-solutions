class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string paren, int open, int closed, int n){
        if(closed == n){
            ans.push_back(paren);
            return;
        }
        if(open < n){
            paren += '(';
            backtrack(ans, paren, open + 1, closed, n);
            paren.pop_back();
        }
        if(open > closed){
            paren += ')';
            backtrack(ans, paren, open, closed + 1, n);
            paren.pop_back();
        }
    }
};
