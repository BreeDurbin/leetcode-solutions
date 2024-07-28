class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, left = 0, total = 0;
        for(int right=0; right<n; right++){
            while(cache[s[right]]){
                cache[s[left]]--;
                left++;
                ans--;
            }
            cache[s[right]]++;
            ans++;
            total = max(total, ans);
        }
        return total;
    }

private:
    unordered_map<char, int> cache;
};