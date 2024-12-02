class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int m = sentence.size(), n = searchWord.size();
        int currentWord = 1;
        int matched = 0;

        for(int i=0; i<m; i++){
            //cout << "curr " << sentence[i] << " curr matching " << matched << endl;
            if(matched == n){
                return currentWord;
            } else if(sentence[i] == ' '){
                currentWord++;
                matched = 0;
            } else if (matched != -1 && sentence[i] != searchWord[matched]) {
                matched = -1;
            } else if (matched != -1 && sentence[i] == searchWord[matched]){
                matched++;
            }
        }

        return matched == n ? currentWord : -1;
    }
};
