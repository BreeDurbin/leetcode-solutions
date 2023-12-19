class Solution {
public:
    string convert(string s, int rowCount) {
        int n = s.size();
        if(rowCount <= 1 || rowCount >= n) return s;
        vector<string> rows(rowCount);
        string ans = "";
        for(int i = 0, row = 0, rowStep = 1; i < n; i++, row+=rowStep){
            rows[row].push_back(s[i]);
            if(row == rowCount-1) rowStep = -1;
            if(row == 0) rowStep = 1;
        }

        for(string row : rows){
            ans += row;
        }

        return ans;
    }
};