class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int m = nums.size();
        if(m == 1) return true;
        int arrayType = 0; //0 = unknown, -1 = monotonic decresing, 1 = monotonic increasing
        for(int i = 1; i<m; i++){
            if(!arrayType){// initialize array type if type is unknown
                if(nums[i] > nums[i-1]) arrayType = 1;
                if(nums[i] < nums[i-1]) arrayType = -1;
            }
            if(arrayType == 1 && nums[i] < nums[i-1]){// increasing array break case
                return false;
            }
            else if(arrayType == -1 && nums[i] > nums[i-1]){ //decreasing array break case
                return false;
            }
        }

        return true;
    }
};
