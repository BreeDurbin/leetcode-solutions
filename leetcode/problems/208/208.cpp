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
        cout << "SEARCH " << word << endl; 
        return searchRec(word, head);
    }

    bool searchRec(string word, TrieNode *node){
        cout << " char " << word[0] << endl;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */