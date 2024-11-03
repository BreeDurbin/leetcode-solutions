struct TrieNode {
    bool is_word = false;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:

    TrieNode* trie = new TrieNode();

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(auto word : words) add(word);

        unordered_set<string> ans_set;

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                backtrack(board, row, col, trie, ans_set, "");
            }
        }

        vector<string> ans;
        for(auto w : ans_set) ans.push_back(w);

        return ans;
    }

    void add(string word){
        TrieNode* node = trie;
        for(auto c : word){
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }

    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void backtrack(vector<vector<char>>& board, int row, int col, TrieNode* trie, unordered_set<string>& ans, string word){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if(!trie->children.count(board[row][col])) return;

        char temp = board[row][col];
        trie = trie->children[temp];
        word += temp;
        if(trie->is_word) ans.insert(word);

        board[row][col] = '*';

        for(auto dir : dirs){
            backtrack(board, row + dir.first, col + dir.second, trie, ans, word);
        }

        board[row][col] = temp;
    }
};
