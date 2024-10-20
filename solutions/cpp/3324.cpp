class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";
        for(int i=0; i<target.size(); i++){
            for(char j = 'a'; j <= target[i]; j++){
                ans.push_back(temp + j);
                if(j == target[i]) temp += j;
            }
        }
        return ans;
    }
};
