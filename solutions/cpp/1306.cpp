class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, -1);

        return dfs(start, arr, vis);
    }

    bool dfs(int i, vector<int>& arr, vector<int>& vis){
        if(i < 0 || i >= arr.size()) return false;
        if(vis[i] != -1) return false;
        vis[i] = true;
        if(arr[i] == 0) return true;

        bool ans = dfs(i + arr[i], arr, vis);
        ans |= dfs(i - arr[i], arr, vis);

        return ans;
    }
};
