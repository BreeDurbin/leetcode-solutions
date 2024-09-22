class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> map;
        for(auto & word : bannedWords){
            map[word]++;
        }
        
        int bannedCount = 0;
        for(auto& word : message){
            if(map.find(word) != map.end()) bannedCount++;
        }
        
        return bannedCount > 1 ? true : false;
    }
};
