class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev = {0, 1, 0};
        ans.push_back({1});

        for(int i=1; i<numRows; i++){
            vector<int> cur = {0};
            for(int i=0; i<prev.size()-1; i++){
                cur.push_back(prev[i] + prev[i+1]);
            }
            cur.push_back(0);
            ans.emplace_back(cur.begin()+1, cur.end()-1);
            prev = cur;
        }

        return ans;
    }
};
