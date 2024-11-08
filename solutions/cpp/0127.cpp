class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        int n = beginWord.size();

        for(auto word : wordList){
            for(int i = 0; i < n; i++){
                string temp = word.substr(0,i) + '*' + word.substr(i+1, n);
                adj[temp].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_map<string, bool> v;
        v[beginWord] = true;

        while(!q.empty()){
            pair<string, int> node = q.front();
            q.pop();
            string word = node.first;
            int level = node.second;

            for(int i = 0; i < n; i++){
                string pattern = word.substr(0,i) + '*' + word.substr(i+1, n);

                for(string adjWord : adj[pattern]){
                    if(adjWord == endWord) return level + 1;

                    if(!v[adjWord]){
                        v[adjWord] = true;
                        q.push({adjWord, level + 1});
                    }
                }
            }
        }

        return 0;
    }
};
