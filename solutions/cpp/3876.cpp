class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        int base_target = nums1[0];

        //if base_target is even then the entire array must be even.
        if(base_target % 2 == 0){
            for(auto num : nums1) if(num % 2 == 1) return false;
            return true;
        }

        // since not even this is the odd case. 
        // for every even number in this array there is at least 1 odd number
        // which is base_target -> therefore every even number can be made odd
        // by subtracting base_target so just return true;

        return true;
    }
};
