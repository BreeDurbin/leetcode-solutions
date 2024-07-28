#define pb push_back

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), rowSize = 0;
        vector<vector<string>> rows;
        rows.pb(vector<string>());
        rows[0].pb(words[0]);
        rowSize += words[0].size();
        vector<string> ans;

        for(int i=1, row=0; i<n; i++){
            // add a new word if can affor space
            if(rowSize + 1 + words[i].size() <= maxWidth){
                rows[row].pb(" ");
                rows[row].pb(words[i]);
                rowSize += 1 + words[i].size();
            }
            // fill with spaces until full if cant add word
            else {
                // fill with spaces until rowSize == maxWidth
                int spaceIndex = 1;
                while(rowSize < maxWidth){
                    if(rows[row].size() == 1) rows[row].pb(" ");
                    else rows[row][spaceIndex] += " ";
                    rowSize++;
                    spaceIndex += 2;
                    if(spaceIndex >= rows[row].size()) spaceIndex = 1;
                }

                //go next row
                row++;
                //seed first word in row
                rows.pb(vector<string>());
                rows[row].pb(words[i]);
                // set rowsize to include first word we just seeded
                rowSize = words[i].size();
            }
        }

        // print all rows into ans
        for(int row=0; row<rows.size(); row++){
            string newRow = "";
            for(int col=0; col<rows[row].size(); col++){
                newRow += rows[row][col];
            }
            ans.pb(newRow);
        }

        while(ans[ans.size()-1].size() < maxWidth) ans[ans.size()-1] += " ";

        return ans;
    }
};