class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::cout << "word1: " << word1 << " word2: " << word2 << " word1 size: " << word1.size() << " word2 size: " << word2.size() << std::endl;
        
        int totalSize = word1.size() + word2.size();
        int minSize = std::min(word1.size(), word2.size());
        int maxSize = std::max(word1.size(), word2.size());
        char ret[totalSize + 1];
        ret[totalSize] = 0;

        for(int i = 0; i < minSize; i++){
            ret[2*i] = word1[i];
            ret[2*i+1] = word2[i];
        }

        string bigString;
        if(word1.size() == maxSize){
            bigString = word1.c_str();
        }
        if(word2.size() == maxSize){
            bigString = word2.c_str();
        }

        for(int i = minSize; i < maxSize; i++){
            ret[minSize + i] = bigString[i];
        }

        return ret;
    }
};