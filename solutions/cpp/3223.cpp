class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;

        for(auto c : s) freq[c]++;

        int ans = 0;
        for(auto & [key, val] : freq){
            while(val >= 3) val -= 2;
            ans += val;
        }
        
        return ans;
    }
};
