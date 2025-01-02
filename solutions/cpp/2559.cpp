class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> vowelCount(n + 1, 0);
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});

        for(int i=0; i<n; i++){;
            bool isVowelString = vowels.count(words[i][0]) && vowels.count(words[i].back());
            vowelCount[i+1] = isVowelString ? 1 + vowelCount[i] : vowelCount[i];
        }

        vector<int> ans(queries.size(), 0);
        for(int i=0; i<queries.size(); i++){
            ans[i] = vowelCount[queries[i][1] + 1] - vowelCount[queries[i][0]];
        }

        return ans;
    }
};
