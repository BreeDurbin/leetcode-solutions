class Solution {
public:

    bool isSubsequence(string sequence, string candidate){
        if(sequence.length()>candidate.length()) return false;
        int j=0;
        for(int i=0; i < candidate.size() && j < sequence.size(); i++){
            if(sequence[j]==candidate[i]) j++;
        }
        return j == sequence.size();
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), less<string>());
        int ans = -1;
        for(int i=0; i<strs.size(); i++){
            bool found = true;
            for(int j = 0; j<strs.size(); j++){
                if(i != j && isSubsequence(strs[i], strs[j])){
                    found = false;
                    break;
                }
            }
            if(found) ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
};