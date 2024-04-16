class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int freq1[26] = {0}, freq2[26] = {0};
        
        //store the freq of every char in s1 in a map
        //some permutation of s1 needs to be in a substring of s2 size s1.size
        // ergo all chars need to match but the order does not need to match
        for(auto& c : s1){
            freq1[c - 'a']++;
        }

        //sliding count of the number of matches for the current substring
        int matches = 0;
        for(int i=0; i<n2; i++){
            // add to freq map
            freq2[s2[i] - 'a']++;
            // if freq of char matches add the freq to matches
            if(freq1[s2[i] - 'a'] == freq2[s2[i] - 'a']) matches += freq1[s2[i] - 'a'];
            // decrement any matches from the falling off edge of the window
            if(i - n1 >= 0 && freq1[s2[i-n1] - 'a'] == freq2[s2[i-n1] - 'a']) matches -= freq1[s2[i-n1] - 'a'];
            //decrement freq of the char falling out of the sliding window range;
            if(i - n1 >= 0) freq2[s2[i-n1] - 'a']--;
            //check if we have matches for every character in s1
            if(matches == n1) return true;
        }

        return false;
    }
};