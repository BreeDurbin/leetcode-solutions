class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // counts of unique characters are the only thing that matters
        if(word1.size() != word2.size()) return false;
        int n = word1.size();

        unordered_map<char, int> word1_map(n);
        unordered_map<char, int> word2_map(n);



        for(int i=0; i < n; i++){
            word1_map[word1[i]]++;
            word2_map[word2[i]]++;
        }

        vector<int> word1_vals;
        vector<int> word2_vals;

        cout << "hi" << endl;
        for(const auto& [key, val] : word1_map){
            //cout << "hi" << key << "  " << val << endl;
            //bool is_found = word2_map.find(key) != word2_map.end();
            //cout << "hi" << is_found << "  " << endl;
            if(word2_map.find(key) == word2_map.end()) return false;
            word1_vals.push_back(val);
        }
        cout << "hi" << endl;
        for(const auto& [key, val] : word2_map){
            if(word1_map.find(key) == word1_map.end()) return false;
            word2_vals.push_back(val);
        }
        cout << "hi" << endl;

        sort(word1_vals.begin(), word1_vals.end());
        sort(word2_vals.begin(), word2_vals.end());

        for(int i=0; i<word1_vals.size();i++){
            //cout << "i " << i << "word1_vals[i]: " << word1_vals[i] << " word1_vals[i]: " << word2_vals[i] << endl;
            if(word1_vals[i] != word2_vals[i]) return false;
        }

        return true;
    }
};