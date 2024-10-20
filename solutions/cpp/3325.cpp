class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            unordered_map<char, int> m;
            //count all chars
            for(int j = i; j < s.size(); j++){
                m[s[j]]++;
                // look at all counts and add increment the substring 
                for(auto & [c, count] : m){
                    if(count >= k){
                        //cout << "c " << c << " cnt " << count << endl;
                        //cout << "inc " << "j=" << j << " i " << i << endl; 
                        ++ans;
                        break;
                    }
                }
            }

        }

        return ans;
        
    }
};
