class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> cache(n-1);
        int ans = 0;
        
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]) cache[i-1] = 1;
            if(nums[i-1] == nums[i]) cache[i-1] = 0;
            if(nums[i-1] > nums[i]) cache[i-1] = -1;
        }
        
        /*for(int i=0; i<n-1; i++){
            cout << "cache[" << i << "]: " << cache[i] << endl;
        )*/
        
        for(int i=0; i<=cache.size()-m; i++){
            int match_count = 0;
            for(int j=0; j<m; j++){
                
                /*cout << "i: " << i << " j: " << j << 
                    " cache[" << j << "]: " << cache[i+j] << 
                    " pattern[j]: " << pattern[j] << endl; */
                
                if(cache[i+j] != pattern[j]) break;
                if(++match_count == m){
                    //cout << "match found" << endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};