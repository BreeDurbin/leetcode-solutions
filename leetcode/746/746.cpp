class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev=cost[1], prevprev=cost[0];
        for(int i = 2; i < n; i++){
            int cur = cost[i] + min(prev, prevprev);
            prevprev=prev;
            prev=cur;
        }
        return min(prev, prevprev);
    }
};