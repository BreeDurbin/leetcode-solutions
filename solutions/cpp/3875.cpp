class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // case 1: nums1 is all even or all odd, then return true;

        // case 2: if nums1 has odds and evens then:
        
        // case 2a: To construct all evens we need at least 2 odds
        // to make an odd into an even we subtract an odd from it
        
        // case 2b: all odds, to make and even into an odd we subtract an odd from it
        // so if there is at least 1 odd we can always make an all odd array

        // so case 1 is always true and case 2 is always true so just return true.

        return true;
    }
};
