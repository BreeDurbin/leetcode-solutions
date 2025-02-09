class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int m = groups.size(), n = elements.size();
        vector<int> ans(m, -1);
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++) if(!mp.count(elements[i])) mp[elements[i]] = i;

        for(int i=0; i<m; i++){
            check(groups[i], mp, ans, i);
        }

        return ans;
    }

    void check(int target, unordered_map<int,int>& m, vector<int>& ans, int index){
        int canidate = INT_MAX;
        for(int i=1; i*i<=target; i++){
            if(target % i == 0){
                if(m.count(i)) canidate = min(canidate, m[i]);
                if(m.count(target/i) && target/i != i) canidate = min(canidate, m[target/i]);
            }
        }
        if(canidate != INT_MAX) ans[index] = canidate;
    }
};
