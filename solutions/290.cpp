class Solution {
    unordered_map<char, string> letters_to_words;
    unordered_map<string, char> words_to_letters;
    
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s, ' ');
        if(pattern.size() != words.size()) return false;

        for(int i=0; i<pattern.size(); i++){
            if(!letters_to_words.contains(pattern[i])) letters_to_words[pattern[i]] = words[i];
            else if (letters_to_words[pattern[i]] != words[i]) return false;
            if(!words_to_letters.contains(words[i])) words_to_letters[words[i]] = pattern[i];
            else if (words_to_letters[words[i]] != pattern[i]) return false;
        }

        return true;
    }

private:
    std::vector<std::string> split (const std::string &s, char delim) {
        std::vector<std::string> result;
        std::stringstream ss (s);
        std::string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }
};