class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size()) return "";
        int m = s.size(), need = t.size();
        pair<int, int> ans = {0,0};

        unordered_map<char, int> need_map;
        for(auto & c : t) need_map[c]++;


        unordered_map<char, int> window;
        int have = 0, right = 0, left = 0;


        for(int left = 0; left < m; left++){

            //expand window out to the right until we get a match or reach the end of the string
            while(have < need && right < m){
                window[s[right]]++;
                if(window[s[right]] <= need_map[s[right]]){
                    have++;
                }
                right++;
            }

            //update ans if a new smaller match is found
            if(have == need){
                // ans is empty string case
                if(ans.second - ans.first == 0){
                    ans = {left, right};
                }
                // ans is smaller than current solution case
                else if(right - left < ans.second - ans.first){
                    ans = {left, right};
                }
            }

            //shrink window left bound
            if(window[s[left]] == need_map[s[left]]) have--;
            window[s[left]]--;

        }

        return s.substr(ans.first, ans.second - ans.first);
    }
};