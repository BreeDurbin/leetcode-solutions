class Solution {
public:
    int maxDifference(string s) {
        int m = s.size();
        unordered_map<char, int> f;
        for(auto c : s) f[c]++;
        int max_odd = INT_MIN, min_even = INT_MAX;

        for(auto & [key, val] : f){
            if(val % 2 == 1) max_odd = max(max_odd, val);
            else min_even = min(min_even, val);
        }

        return max_odd - min_even;
        
        
    }
};
