class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int ans = 0;

        int cur_min = -1;
        for(int i=n-1; i>=0; i--){
            if(cur_min == -1){
                // starting a new shipment
                cur_min = weight[i];
                continue;
            }
            if(cur_min < weight[i]){
                // balanced
                ans++;
                cur_min = -1;
            } else {
                // update the last parcel to be the current index since its smaller or equal size
                cur_min = weight[i];
            }
        }
        
        return ans;
    }
};
