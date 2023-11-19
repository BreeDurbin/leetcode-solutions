static int fast_io = []() { 
	std::ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	return 0; 
}();

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, ans = 0;
        while(left < right){
            if(nums[left] + nums[right] == k){
                left++;
                right--;
                ans++;
            }
            else if(nums[left] + nums[right] > k){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};