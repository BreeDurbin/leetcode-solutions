class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.size() <= k){
            string temp = word;
            for(auto & c : temp) c = c == 'z' ? 'a' : c + 1;
            word += temp;
        }

        return word[k-1];
    }
};
