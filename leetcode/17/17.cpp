class Solution {
public:

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        return dfs(digits, letters);
    }

    const vector<string> dfs(string digits, const vector<string>& letters){
        if(digits.size() == 0) return {};
        vector<string> ans;
        string substring = digits.substr(1,digits.size()-1);
        int digit = digits[0] - '0';
        for(int i=0; i<letters[digit].size(); i++){
            vector<string> tails = dfs(substring, letters);
            if(tails.size()==0){ 
                ans.push_back({letters[digit][i]});
            }
            for(auto& tail : tails){
                ans.push_back(letters[digit][i] + tail);
            }
        }
        return ans;
    }
};