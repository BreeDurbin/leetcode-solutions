class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        int prev = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == prev + 1){
                sum += nums[i];
                prev = nums[i];
            } else {
                break;
            }
        }

        return findSmallenstIntGreaterThanOrEqualToSumThatIsNotInTheArray(nums, sum);
    }

    int findSmallenstIntGreaterThanOrEqualToSumThatIsNotInTheArray(vector<int>& nums, int sum){
        unordered_map<int,int> num_map;

        for(auto num : nums) num_map[num]++;

        while(num_map.contains(sum)){ sum++; };

        return sum;
    }
};
