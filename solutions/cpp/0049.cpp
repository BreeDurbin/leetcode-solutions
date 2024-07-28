class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHasher> grouped;

        for(int i=0; i<strs.size(); i++){
            vector<int> key(26);
            for(int j=0; j<strs[i].size(); j++){
                key[strs[i][j] - 'a']++;
            }
            grouped[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto kv : grouped) ans.push_back(kv.second);

        return ans;
    }

private:
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            int hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
};