struct TrieNode {
    TrieNode *children[26];
    bool endsHere = false;

    bool containsKey(char c){
        return children[c - 'a'] != nullptr;
    }

    void putKey(char c){
        if(!containsKey(c)) children[c - 'a'] = new TrieNode();
    }

    TrieNode* getKey(char c){
        return children[c - 'a'];
    }

    void setEnd(){
        endsHere = true;
    }

    bool isEnd(){
        return endsHere;
    }
};

class Trie {
public:
    TrieNode *head = nullptr;

    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        insertRec(word, head);
    }

    void insertRec(string word, TrieNode *node) {
        if(word.size() != 0) {
            node->putKey(word[0]);
            insertRec(word.substr(1, word.size() - 1), node->getKey(word[0]));
        } else{
            node->setEnd();
        }
    }
    
    bool search(string word) {
        return searchRec(word, head);
    }

    bool searchRec(string word, TrieNode *node){
        if(word.size() > 0){
            if(!node->containsKey(word[0])) return false;
            return searchRec(word.substr(1,word.size() - 1), node->getKey(word[0]));
        }
        return node->endsHere;
    }
    
    bool startsWith(string prefix) {
        return startsWithRec(prefix, head);
    }

    bool startsWithRec(string prefix, TrieNode *node){
        if(prefix.size() > 0){
            if(node->containsKey(prefix[0])){
                return startsWithRec(prefix.substr(1,prefix.size() - 1), node->getKey(prefix[0]));
            }
            else{ 
                return false;
            }
        }
        return true;
    }

    //Returns an array of suggestions of size as close to resultCount as possible. 
    vector<string> search(string prefix, int resultCount) {
        vector<string> result;
        TrieNode *current = head;
        for(char &c : prefix){
            if(!current->containsKey(c)){
                return result;
            }
            current = current->getKey(c);
        }
        return dfs_suggest(prefix, current, resultCount, result);
    }

    vector<string> dfs_suggest(string prefix, TrieNode *node, int resultCount, vector<string> &result){
        if(result.size() == resultCount) return result;
        if(node->isEnd()) result.push_back(prefix);
        for(char c = 'a'; c <= 'z'; c++){
            if(node->containsKey(c)){
                prefix += c;
                dfs_suggest(prefix, node->getKey(c), resultCount, result);
                prefix.pop_back();
            }
        }

        return result;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for(auto& product : products){
            trie.insert(product);
        }
        vector<vector<string>> answer;
        string prefix = "";
        for(auto &letter : searchWord){
            prefix += letter;
            answer.push_back(trie.search(prefix, 3));
        }
        return answer;
    }
};