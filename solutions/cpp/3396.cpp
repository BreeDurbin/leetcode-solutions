class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i+=3, ans++){
            unordered_map<int,int> f;
            for(int j = i; j < nums.size(); j++){
                //if we encounter a dupe go to next iteration
                f[nums[j]]++;
            }
            int isUnique = true;
            for(auto [key, val] : f){
                //cout << "key " << key << " val " << val << endl;
                if(val > 1) isUnique = false;
            }
            if(isUnique) return ans;
        }

        return ans;
    }
};
