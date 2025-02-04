class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0, v=0;

        for(auto& c : moves){
            h += (c == 'R');
            h -= (c == 'L');
            v += (c == 'U');
            v -= (c == 'D');
        }
        
        return h==0 && v==0;
    }
};
