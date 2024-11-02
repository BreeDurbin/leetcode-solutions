struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool complete = false;
};

class WordDictionary {
public:

    TrieNode* trie = new TrieNode();

    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* node = trie;
        for(auto c : word){
            if(!node->children.count(c)) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->complete = true;
    }
    
    bool search(string word) {
        return search_helper(word, trie);
    }

    bool search_helper(string word, TrieNode* node){
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            if(!node->children.count(c)){
                if(c == '.'){
                    for(auto t : node->children){
                        if(search_helper(word.substr(i+1), t.second)) return true;
                    }
                }
                return false;
            }
            else node = node->children[word[i]];
        }

        return node->complete;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
