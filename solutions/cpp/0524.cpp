class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = dictionary.size();
        
        for(auto word : dictionary){
            if(canFormByDeleting(word, s)){
                if(ans.size() < word.size() || (ans.size() == word.size() && ans.compare(word) > 0)){
                    ans = word;
                }
            }
        }
        
        return ans;
    }

    //word the word we want to form by deleting
    // str the string we want to make into word bu deleting chars.
    // NOTE: deletion does not let us change the order of chars so we cant use a dictionary for this.
    bool canFormByDeleting(string word, string str){
        int word_i = 0, str_i = 0;
        while(word_i < word.size() && str_i < str.size()){
            if(word[word_i] == str[str_i]) word_i++;
            str_i++;
        }

        return word_i == word.size();
    }
};