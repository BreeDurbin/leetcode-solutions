class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // if r1.x1 r1.x2 overlap with r2.x1 and r2.x2 then we have x axis overlap
        // we can do the same thing with the y axis if both are true then we have overlap

        int r1_x1 = rec1[0], r1_x2 = rec1[2], r1_y1 = rec1[1], r1_y2 = rec1[3]; 
        int r2_x1 = rec2[0], r2_x2 = rec2[2], r2_y1 = rec2[1], r2_y2 = rec2[3]; 

        bool x_overlap = r1_x1 < r2_x2 && r2_x1 < r1_x2;
        bool y_overlap = r1_y1 < r2_y2 && r2_y1 < r1_y2;;

        return x_overlap && y_overlap;
    }
};
