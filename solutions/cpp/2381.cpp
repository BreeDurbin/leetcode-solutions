class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffs(s.size() + 1);
        for(auto t : shifts){
            int left = t[0], right = t[1], shift = t[2];
            if(shift == 1){
                diffs[left]++;
                diffs[right+1]--;
            }
            else{
                diffs[left]--;
                diffs[right+1]++;
            }
        }
        int diff = 0;
        for(int i=0; i<s.size(); i++){
            diff = (diff + diffs[i]) % 26;
            if(diff < 0) diff += 26;
            s[i] =  'a' + (s[i] - 'a' + diff) % 26;
        }
        return s;
    }
};
