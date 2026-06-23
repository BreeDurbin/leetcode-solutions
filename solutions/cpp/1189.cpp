class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() < 7) return 0;
        unordered_map<char, int> f;
        for(auto t : text){
            f[t]++;
        }

        int ans = INT_MAX;

        if(f['b'] == 0) return 0;
        if(f['a'] == 0) return 0;
        if(f['n'] == 0) return 0;
        if(f['l'] <= 1) return 0;
        if(f['o'] <= 1) return 0;

        for(auto [index, frequency] : f){
            switch(index){
                case 'b': ans = min(ans, frequency); break;
                case 'a': ans = min(ans, frequency); break;
                case 'l': ans = min(ans, frequency/2); break;
                case 'o': ans = min(ans, frequency/2); break;
                case 'n': ans = min(ans, frequency); break;
            }
        }

        cout << ans << endl;

        return ans == INT_MAX ? 0 : ans;
    }
};
