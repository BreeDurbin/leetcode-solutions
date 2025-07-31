class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        int n = arr.size();
        unordered_set<int> prev;

        for(int i=0; i<n; i++){
            unordered_set<int> cur;
            cur.insert(arr[i]);
            for(int num : prev) cur.insert(arr[i] | num);
            ans.insert(cur.begin(), cur.end());
            prev = cur;
        }


        return ans.size();
    }
};
