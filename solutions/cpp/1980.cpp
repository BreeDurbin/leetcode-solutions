class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> used;
        string cur = "";
        for(auto num : nums) used.insert(num);
        return solve(used, cur, n) ? cur : "";
    }

    bool solve(unordered_set<string>& used, string & cur, int n){
        if(cur.size() == n){
            return used.count(cur) ? false : true;
        }

        cur.push_back('1');
        if(solve(used, cur, n)) return true;
        cur.pop_back();

        cur.push_back('0');
        if(solve(used, cur, n)) return true;
        cur.pop_back();

        return false;
    }
};
