class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int m = nums.size();
        unordered_map<int, int> f;

        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                f[nums[i]*nums[j]]++;
            }
        }

        int ans = 0;
        for(auto & [key, val] : f){
            if(val > 1) ans += 8*(val*(val-1)/2);
        }

        return ans;
    }
};
