class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int c = 0;
        
        vector<pair<double,int>> diagonals_to_areas;
        
        for(auto &rect : dimensions){
            double diag = sqrt(rect[0]*rect[0] + rect[1]*rect[1]);
            int area = rect[0] * rect[1];
            diagonals_to_areas.push_back({diag, area});
        }
        
        double max_diag = 0;
        int ans = 0; 
        for(auto &rect : diagonals_to_areas){
            if(rect.first == max_diag){
                ans = max(rect.second, ans);
                cout << "1st" << rect.second << " 2nd " << ans << endl;
            } else if(rect.first > max_diag){
                max_diag = rect.first;
                ans = rect.second;
            }
        }
        
        return ans;
    }
};