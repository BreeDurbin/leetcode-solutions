class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0; i < n - k + 1; i++){

            //count all copies of each num in the subarray
            unordered_map<int, int> counts;
            for(int j=0; j<k; j++){
                counts[nums[i + j]]++;
            }
            
            priority_queue<pair<int, int>> maxHeap;
            for (auto& entry : counts) {
                maxHeap.push({entry.second, entry.first});
            }
            
            //add the k highest count nums to a hashset
            unordered_set<int> x_nums;
            for(int j = 0; j<x; j++){
                x_nums.insert(maxHeap.top().second);
                maxHeap.pop();
            }
            
            //sum up the k most common nums
            int x_sum = 0;
            for(int j=0; j<k; j++){
                if(x_nums.find(nums[i + j]) != x_nums.end()){ 
                    x_sum += nums[i + j];
                }
            }
            
            ans.push_back(x_sum);
            
        }
        
        return ans;
    }
};
