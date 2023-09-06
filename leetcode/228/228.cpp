class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string temp = "";
        int n = nums.size();
        if(nums.size()==0) return ans;
        if(nums.size()==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        for(int i=0;i<n;i++){
            int start = nums[i];
            while(i+1<n && nums[i]+1==nums[i+1]){
                i++;
            }
            if(start!=nums[i]){
                ans.push_back(to_string(start)+"->"+to_string(nums[i]));
            }
            else{
                ans.push_back(to_string(start));
            }
        }
        return ans;
    }
};