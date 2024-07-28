class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto& a : letters) if(a - '0' > target - '0') return a; 
        return letters[0];
    }
};