class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.size(), k = words.size(), wordLength = words[0].size(), wordsWindow = wordLength * k;

        vector<int> ans;

        for(auto & word : words) wordCount[word]++;

        for(int i = 0; i + wordsWindow <= n; i++){
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLength)) ans.push_back(i);
        }

        return ans;
    }

private:
    unordered_map<string, int> wordCount;

    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLength){
        for(int j=0; j<s.size(); j+=wordLength){
            string word = s.substr(j, wordLength);
            if(wordCount.find(word) != wordCount.end()){
                wordCount[word]--;
                if(wordCount[word] == -1){
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

};