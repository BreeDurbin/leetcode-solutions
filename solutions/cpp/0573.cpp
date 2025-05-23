class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 0, t = INT_MIN;

        for(auto &nut : nuts){
            ans+=dist(nut, tree) * 2;
            t = max(t, dist(nut,tree)-dist(squirrel,nut));
        } 
        
        return ans - t;
    }

    int dist(vector<int> start, vector<int> end){
        return abs(start[0]-end[0]) + abs(start[1]-end[1]);
    }
};
