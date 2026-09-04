class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostDistinctInt(nums, k) - atMostDistinctInt(nums, k - 1);
    }

    int atMostDistinctInt(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> f;

        int left = 0;

        for(int right=0; right<n; right++){

            f[nums[right]]++;

            while(f.size() > k){
                f[nums[left]]--;

                if(f[nums[left]] == 0) f.erase(nums[left]);

                left++;
            }

            count += right - left + 1;
        }


        return count;

    }
};
