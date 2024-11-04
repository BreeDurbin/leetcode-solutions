class Solution {
public:

    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> q;
        q.push({0,0,0,1});

        while(!q.empty()){
            int t = get<0>(q.top()), i = get<1>(q.top()), j = get<2>(q.top()), k = get<3>(q.top());
            q.pop();

            if(i == m - 1 && j == n - 1) return t;

            for(auto dir : dirs){
                int di = i+dir.first, dj = j+dir.second;
                    if(di >= 0 && di < m && dj >= 0 && dj < n){
                    int dt = max(t, moveTime[di][dj]) + k;

                    if(dt < dp[di][dj]){
                        dp[di][dj] = dt;
                        q.push({dt, di, dj, k == 1 ? 2 : 1});
                    };

                }

            }
        }

        return -1;
    }

};
