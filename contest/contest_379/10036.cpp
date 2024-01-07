class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        pair<int, int> rook{a,b}, bishop{c,d}, queen{e,f};

        // rook to take in 1
        if((rook.first == queen.first) || rook.second == queen.second)
        {
            if(abs(bishop.first - queen.first) == abs(bishop.second - queen.second)) return 1;
            
            //if bish is in way return 2
            if(bishop.first > rook.first && bishop.first < queen.first){
                if(bishop.second == queen.second) return 2;
            }
            if(bishop.first < rook.first && bishop.first > queen.first){
                if(bishop.second == queen.second) return 2;
            }
            if(bishop.second > rook.second && bishop.second < queen.second){
                if(bishop.first == queen.first) return 2;
            }
            if(bishop.second < rook.second && bishop.second > queen.second){
                if(bishop.first == queen.first) return 2;
            }
            
            return 1;
        }
        
        //bishop to take in 1
        if(abs(bishop.first - queen.first) == abs(bishop.second - queen.second)){
            //if rook is in way return 2
            if(abs(bishop.first - rook.first) == abs(bishop.second - rook.second)){
                if(bishop.first < rook.first && rook.first < queen.first){
                    return 2;
                }
                if(bishop.first > rook.first && rook.first > queen.first){
                    return 2;
                }
            }
            return 1;
        }
        
        return 2;
    }
};