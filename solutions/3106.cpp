class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        for(char i : s){
            for(char j='a'; j<='z'; j++){
                int dist = abs((i - 'a') - (j - 'a'));
                dist = min(dist, 26 - dist);
                if(dist <= k){
                    k -= dist;
                    ans += j;
                    break;
                }
            }
        }
        return ans;
    }
};