class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<string, unordered_map<char, int>> universal_dict;

        //words 1 freq map
        for(auto w : words1){
            for(int i=0; i<w.size(); i++){
                universal_dict[w][w[i]]++;
            }
        }

        //words 2 frewq map
        unordered_map<char, int> words2_freq;
        for(auto subset_candidate : words2){
            unordered_map<char, int> candidate_freq;
            for(auto c : subset_candidate) candidate_freq[c]++;
            for(auto [c, val] : candidate_freq){
                if(words2_freq[c] < val){
                    words2_freq[c] = val;
                }
            }
        }

        for(auto universal : words1){
            bool is_universal = true;
            for(auto [c, val] : words2_freq){
                if(universal_dict[universal][c] < val){
                    is_universal = false;
                    break;
                }
            }
            if(is_universal) ans.push_back(universal);
        }

        return ans;
    }
};
