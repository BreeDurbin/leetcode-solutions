class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        multimap<int,int> m;
        int ans = 0;
        for(int i=0; i<reward1.size(); i++){
            m.insert({reward2[i]-reward1[i], i});
        }
        for(auto i = m.begin(); i != m.end(); i++){
            if(k){
                ans += reward1[i->second];
                --k;
            } else {
                ans += reward2[i->second];
            }
        }
        return ans;
    }
};
