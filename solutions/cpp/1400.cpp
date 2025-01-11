class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;

        unordered_map<char, int> freq;
        for(auto c : s) freq[c]++;

        int odd_freq = 0, even_freq = 0;
        for(auto & [key, val] : freq){
            if(val % 2 == 0) even_freq++;
            else odd_freq++;
        }

        return odd_freq <= k ? true : false;
        
    }
};
