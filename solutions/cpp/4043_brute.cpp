class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        //A cyclic rotation of s is obtained by choosing a prefix of s whose length is between 0 and n - 1 (inclusive), and moving it to the end of the string while preserving the order of all characters.

        //For every cyclic rotation of s, let its score be the number of indices i such that 0 <= i < n - 1 and the characters at positions i and i + 1 are equal.

        // count the number of cyclic rotations of s with score k

        int count_s_equals_k = 0;

        // how do I get score? score = number of indices of i in s where the positions of i and i + 1 are equal
        for(int i=0; i<n; i++){
            string rotation = s.substr(i) + s.substr(0, i);
            cout << "i: " << i << " " << rotation << endl;
            count_s_equals_k += get_s_equals_k(rotation, k);
        }

        return count_s_equals_k;
    }

    int get_s_equals_k(string s, int k){
        int count = 0;
        
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) count++;
        }

        return count == k;
    }
};
