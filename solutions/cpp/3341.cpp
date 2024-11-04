class Solution {
public:

    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});

        while(!q.empty()){
            int t = q.top().first, i = q.top().second.first, j = q.top().second.second;
            q.pop();

            if(i == m - 1 && j == n - 1) return t;

            for(auto dir : dirs){
                int di = i+dir.first, dj = j+dir.second;
                    if(di >= 0 && di < m && dj >= 0 && dj < n){
                    int dt = max(t, moveTime[di][dj]) + 1;

                    if(dt < dp[di][dj]){
                        dp[di][dj] = dt;
                        q.push({dt, {di, dj}});
                    };

                }

            }
        }

        return -1;
    }

};
