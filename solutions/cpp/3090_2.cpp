class Solution {
public:
    int maximumLengthSubstring(string s) {
        // sliding window 
        // expand out to the right with a for loop
        // when invariant isnt met collapse in from the left with a while loop

        // invariant: count[s[right]] > 2

        unordered_map<char,int> count;

        int ans = 0;

        for(int right = 0, left = 0; right < s.size(); right++){
            count[s[right]]++;

            while(count[s[right]] > 2){
                count[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
