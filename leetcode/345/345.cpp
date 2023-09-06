class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;


        
        while(i < j){
            while(i < j && !isVowel(s[i])){
                i++;
            }
            while(j > i && !isVowel(s[j])){
                j--;
            }
            
            auto t = s[i];
            s[i] = s[j];
            s[j] = t;

            i++;
            j--;
            
        }
        return s;
    }

private:
    bool isVowel(char &ch) {
        return ch =='a' || ch == 'e' || ch =='i' || ch == 'o' ||ch == 'u' ||
               ch =='A' || ch == 'E' || ch =='I' || ch == 'O' || ch == 'U';
    }
};