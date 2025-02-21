class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<int,int> freq;
        for(auto c : tiles) freq['A' - c]++;
        return solve(freq);
    }

    int solve(unordered_map<int,int>& freq){
        int ans = 0;
        for(auto & [c, f] : freq){
            if(f > 0){
                freq[c]--;
                ans += 1 + solve(freq);
                freq[c]++;
            }
        }
        return ans;
    }
};
