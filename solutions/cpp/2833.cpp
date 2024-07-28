class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int min_dist_l = 0;
        int max_dist_r = 0;
        int curr = 0;
        //all left
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'L' || moves[i] == '_'){
                curr--;
            } else {
                curr++;
            }
            min_dist_l = min(min_dist_l, curr);
        }
        min_dist_l = curr;
        
        //all right
        curr = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'R' || moves[i] == '_'){
                curr++;
            } else {
                curr--;
            }
            max_dist_r = max(max_dist_r, curr);
        }
        max_dist_r = curr;
        
        cout << "L: " << min_dist_l << " R: " << max_dist_r << endl;
        
        return max(abs(min_dist_l),abs(max_dist_r));
        
    }
};