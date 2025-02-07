class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> i_to_c;
        unordered_map<int,unordered_set<int>> c_to_i;
        vector<int> ans;

        for(auto q : queries){
            int ball = q[0], color = q[1];
            if(i_to_c.find(ball) != i_to_c.end()) {
                //purge ball from c_to_i
                int old_color = i_to_c[ball];
                c_to_i[old_color].erase(ball);
                //purge color from c_to_i if it is empty
                if(c_to_i[old_color].size() == 0) c_to_i.erase(old_color);
            }

            //handle query
            c_to_i[color].insert(ball);
            i_to_c[ball] = color;

            ans.push_back(c_to_i.size());
        }

        return ans;
    }
};
