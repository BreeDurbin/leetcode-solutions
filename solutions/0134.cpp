class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tank = 0, start = 0, missing = 0;
        for(int i=0; i<n; i++){
            // fill up gas at ith station
            // subtract gas to get to i++ station
            tank += gas[i] - cost[i];
            // travel to next station if we dont have nergative gas.
            // negative gas means we ran out before reaching the i++ station
            if(tank<0){
                missing += tank;
                start = i+1;
                tank = 0;
            }
        }

        if(missing + tank >= 0) return start;
        return -1;
    }
};