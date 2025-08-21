class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        //assume that there are no missing positives
        // put each int in its sorted place were there no positives
        for(int i=0; i<n; i++) 
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
                swap(nums[i], nums[nums[i] - 1]);

        // second pass check if any num is out of place
        for(int i=0; i<n; i++) if(nums[i] != i + 1) return i + 1;

        return n + 1;
    }
};
