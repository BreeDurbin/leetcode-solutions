class Solution {
public:
    bool isRobotBounded(string instructions) {
        int horiz = 0, vert = 0;
        int dir = 0;// 1 is up, 2 is right, 3 is down, 4 is left
        for(auto i : instructions){
            if(i == 'L') dir = (dir + 3) % 4;
            else if(i == 'R') dir = (dir + 1) % 4;
            else{
                if(dir == 0) vert++;
                if(dir == 1) horiz++;
                if(dir == 2) vert--;
                if(dir == 3) horiz--;
            }
        }

        return (horiz == 0) && (vert == 0) || dir > 0;
    }
};
