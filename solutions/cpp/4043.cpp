class Solution {
public:
    int countRotations(string s, int k) {
        int number_of_rotations = s.size();
        int adj_pairs = 0;

        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) adj_pairs++;
        }
        if(s[0] == s[s.size()-1]) adj_pairs++;

        if(k == adj_pairs) return number_of_rotations - adj_pairs;
        if(k == adj_pairs - 1) return adj_pairs;

        return 0;
    }

};
