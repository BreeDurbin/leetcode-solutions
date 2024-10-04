class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> col, diag, anti;
        return backtrack(n,0,col,diag,anti);
    }

    int backtrack(int n, int r, unordered_set<int> cols, unordered_set<int> diags, unordered_set<int> antis){
        if(r == n){
            return 1;
        }
        int ans = 0;
        for(int c = 0; c != n; c++){
            if(
                cols.find(c) != cols.end() ||
                diags.find(r-c) != diags.end() ||
                antis.find(r+c) != antis.end()
            ) continue;

            cols.insert(c);
            diags.insert(r-c);
            antis.insert(r+c);
            ans += backtrack(n,r+1,cols,diags,antis);
            cols.erase(c);
            diags.erase(r-c);
            antis.erase(r+c);
        }
        return ans;
    }
};
