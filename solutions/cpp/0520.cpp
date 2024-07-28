class Solution {
public:
    bool detectCapitalUse(string word) {
        //three cases 
        //"USA", "leetcode", "Google". patterns are right else false
        
        //check if USA
        bool caps = true;
        for(auto c : word){
            if(isupper(c) == 0) caps = false;
        }
        if(caps) return true;
        
        //check if all lower
        bool lower = true;
        for(auto c : word){
            if(islower(c) == 0) lower = false;
        }
        if(lower) return true;
        
        //check if first is upper then all are lower
        bool case_3 = isupper(word[0]) != 0 ? true : false;
        //cout << "case 3" << case_3 << endl;
        for(int i=1; i< word.size(); i++){
            if(islower(word[i]) == 0) case_3 = false;
        }
        if(case_3) return true;
        
        return false;
    }
};