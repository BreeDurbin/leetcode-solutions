class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";

        int n = s.size();

        vector<int> prefix_sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + (s[i] == '1');
        }

        for(int left=0, right = 0; right<s.size(); right++){

            while(left <= right && prefix_sum[right + 1] - prefix_sum[left] > k){
                left++;
            }

            while (left <= right && s[left] == '0') left++;

            if (prefix_sum[right + 1] - prefix_sum[left] == k) {
                string candidate = s.substr(left, right - left + 1);

                if (ans == "" ||
                    candidate.size() < ans.size() ||
                    (candidate.size() == ans.size() && candidate < ans)) {
                    ans = candidate;
                }
            }
        }

        return ans;
    }
};
