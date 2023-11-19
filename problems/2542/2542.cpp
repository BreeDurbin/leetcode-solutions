class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // nums[i].first is nums2[i] and nums[i].second is nums1[i]
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back(make_pair(nums2[i],nums1[i]));
        }
        sort(nums.begin(),nums.end());
        long long ans = 0, curr_sum = 0;

        priority_queue<int,vector<int>, greater<int>> min_heap;

        for(int i=n-1; i>n-1-k; i--){
            min_heap.push(nums[i].second);
            curr_sum+=nums[i].second;
        }
        ans = curr_sum*nums[n-k].first;

        for(int i=n-1-k; i>=0; i--){
            curr_sum-=min_heap.top();
            min_heap.pop();
            curr_sum+=nums[i].second;
            min_heap.push(nums[i].second);
            ans=max(ans,curr_sum*nums[i].first);
        }
        return ans;
    }
};