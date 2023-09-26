class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int>& t, vector<int>& u){return t[1] < u[1];});
        int answer = 0, prev = 0;
        for(int i=1; i<intervals.size(); i++){
            int cur = i;
            if(intervals[cur][0] < intervals[prev][1]) answer++;
            else {
                prev=i;
            }
        }
        return answer;
    }
};