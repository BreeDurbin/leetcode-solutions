class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int testedDevices=0, n=batteryPercentages.size();
        
        for(int i=0; i<n; i++){
            if(batteryPercentages[i] > 0){
                testedDevices++;
                for(int j=i+1; j<n; j++){
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        
        return testedDevices;
    }
};