class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j< words.size(); j++){
                //cout << " i " << i << " j " << j << endl;
                if(isPrefixAndSuffix(words[i], words[j])){
                    //cout << "words[i]: " << words[i] << " words[j] " << words[j] << " true" << endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    bool isPrefixAndSuffix(string pref_suff, string str){
        if(pref_suff.size() > str.size()) return false;
        
        //cout << " pref_suff " << pref_suff << " str " << str << endl;

        for(int i=0; i<pref_suff.size(); i++){
            if(str[i] != pref_suff[i] || str[str.size()-1 - i] != pref_suff[pref_suff.size()-1 - i]) return false;
        }
        
        return true;
    }
};