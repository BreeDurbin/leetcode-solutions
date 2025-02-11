class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(auto b : bills){
            if(b == 5) fives++;
            if(b == 10){
                tens++;
                if(fives <= 0) return false;
                fives--;
            }
            if(b == 20){
                if(tens <= 0){
                    if(fives < 3) return false;
                    fives -= 3;
                } else if(tens >= 1){
                    tens--;
                    if(fives <= 0) return false;
                    fives--;
                }
            }
        }
        return true;
    }
};
