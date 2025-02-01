class Solution {
public:
    int romanToInt(string s) {
        int m = s.size(), i = 0, total = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10;
        mp['L'] = 50; mp['C'] = 100; mp['D'] = 500;
        mp['M'] = 1000;

        while(i < m){
            if(i < m - 1 && mp[s[i+1]] > mp[s[i]]){
                total += (mp[s[i+1]] - mp[s[i]]);
                i += 2;  
            }
            else {
                total += mp[s[i]];
                i++;  
            }
        }

        return total;

    }
};
