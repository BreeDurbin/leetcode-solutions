class Solution {
public:
    int reverseDegree(string s) {
        
        vector<int> multiplied(s.size(), 0);

        ///For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            int position = c - 'a';// number of characters from 1
            int reversed = 26 - position;
            int index = i + 1;
            //cout << "index: " << index << " position " << position << " c " << c << " reversed " << reversed << endl;
            multiplied[i] = reversed * index;
        }

        //Sum these products for all characters in the string.
        int ans = 0;
        for(auto num : multiplied) ans += num;

        return ans;
    }
};
