class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*'){
                //std::cout << "count++" << std::endl;
                count++;
            } else if(count == 0){
                //std::cout << "ans+=" << std::endl;
                ans += s[i];
            } else {
                //std::cout << "count--" << std::endl;
                count--;
            }
            //std::cout << "ans:" << ans << std::endl;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};