class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i =0;
        for(auto n : nums){
            n %= 3;
            if(n == 1 || n == 2){ i++; }
        }
        return i;
    }
};
