class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return false;
        int x_move=abs(fx-sx), y_move=abs(fy-sy);
        return max(x_move, y_move) <= t;
    }
};