class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_count = 0;
        int maj_ele = 0;

        for(auto& num : nums){
            if(maj_count == 0){
                maj_ele = num;
            }
            if(num != maj_ele) maj_count--;
            else maj_count++;

        }

        return maj_ele;
    }
};