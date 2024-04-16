class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans = 0;
        //horizontal, vertical, diagonal, anti-diagonal
        vector<vector<int>> h(m, vector<int>(n, 0)), v(m, vector<int>(n, 0)), d(m, vector<int>(n, 0)), a(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!mat[i][j]) continue;
                h[i][j]=v[i][j]=d[i][j]=a[i][j]=1;
                if(check(i-1,j,m,n)) v[i][j] = max(a[i][j], 1 + v[i-1][j]);
                if(check(i,j-1,m,n)) h[i][j] = max(h[i][j], 1 + h[i][j-1]);
                if(check(i-1,j-1,m,n)) d[i][j] = max(d[i][j], 1 + d[i-1][j-1]);
                if(check(i-1,j+1,m,n)) a[i][j] = max(a[i][j], 1 + a[i-1][j+1]);
                ans=max(ans,h[i][j]);
                ans=max(ans,v[i][j]);
                ans=max(ans,d[i][j]);
                ans=max(ans,a[i][j]);
            }
        }
        return ans;
    }

    bool check(int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)
            return false;
        return true;
    }
};