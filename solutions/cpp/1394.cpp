class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> f;
        for(auto i : arr) f[i]++;
        int ans = -1;
        for(auto & [num, freq] : f){
            if(num == freq) ans = max(num, ans);
        }
        return ans;
    }
};
