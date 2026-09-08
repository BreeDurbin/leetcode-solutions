class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, bool> is_special;
        is_special[nums[0]] = true;

        for(int i = 1; i < nums.size(); i++){

            // if is special contains nums[i] and if nums[i - 1] != nums[i] the it is not special
            if(is_special.contains(nums[i]) && nums[i-1] != nums[i]){
                is_special[nums[i]] = false;
            }
            
            // if is special doesnt contains nums[i] add it in and set it as special
            if(!is_special.contains(nums[i])){
                is_special[nums[i]] = true;
            }
        }


        int count = 0;

        for(auto [_, val] : is_special){
            //cout << "k: " << _ << " " << val << endl;;
            if(val) count++;
        }


        return count;
    }
};
