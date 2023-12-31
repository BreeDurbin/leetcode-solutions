class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i + 1; j<nums.size(); j++){
                int temp = nums[i] | nums[j];
                //cout << "i " << i << " j " << j << " temp " << temp << endl;
                if(temp % 2 == 0) return true;
            }
        }
        
        //cout << " hi " << count << endl;
        
        return count >= 1 ? true : false;
    }
};