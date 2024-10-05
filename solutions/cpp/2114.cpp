class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(auto & s : sentences){
            int temp = 0;
            for(int i=0; i<s.size(); i++){
                if(s[i] == ' ') temp++;
            }
            ans = max(ans, temp);
        }

        return ans + 1;
    }
};
