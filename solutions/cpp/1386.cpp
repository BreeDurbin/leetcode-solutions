class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,int> seats; // row, bitmask

        int left   = 0b00001111; // 2-5
        int middle = 0b00111100; // 4-7
        int right  = 0b11110000; // 6-9

        for(auto reserved : reservedSeats){
            if(reserved[1] != 1 && reserved[1] != 10){
                seats[reserved[0]] |= 1 << (reserved[1] - 2);
            }
        }

        int ans = 2* (n - seats.size()); // completely empty rows will not be in the map and each seat 2 families

        // one family case
        for(auto [row, mask] : seats){
            if(
                (mask & left) == 0 ||
                (mask & middle) == 0 ||
                (mask & right) == 0 
            ) { ans++; }
            
        }

        return ans;
    }
};
