class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, emptyBottles = 0;
        
        while(numBottles || numExchange <= emptyBottles){
            if(numBottles > 0){
                ans += numBottles;
                emptyBottles += numBottles;
                numBottles = 0;
            }
            else {
                while(numExchange <= emptyBottles){
                    numBottles++;
                    emptyBottles -= numExchange;
                    numExchange++;
                }
            }
        }
        
        return ans;
    }
};