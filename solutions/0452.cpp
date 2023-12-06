class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(),points.end(), [](const vector<int>& t, vector<int>& u){return t[1] < u[1];});
        int answer = 1;
        vector<int> prev = points[0];
        for(int cur=1; cur<points.size(); cur++){
            if(points[cur][0] > prev[1]){
                answer++;
                prev = points[cur];
            } else {
                prev[1] = min(prev[1], points[cur][1]);
            }
        }
        return answer;
    }
};