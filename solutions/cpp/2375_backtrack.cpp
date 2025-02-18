class Solution {
public:
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        vector<string> canidates;
        string ans = "999999999", canidate = "";
        int m = pattern.size(), index;

        generate_possibilities(pattern, ans, canidate, used, m + 1);

        return ans;
    }

    void generate_possibilities(string& pattern, string& best, string& canidate, vector<bool>& used, int target_size){
        if(canidate.size() == target_size){
            if(check(pattern, canidate)) best = min(canidate, best);
            return;
        }

        for(int i=1; i<=9; i++){
            if(!used[i]){
                canidate.push_back('0' + i);
                used[i] = true;
                generate_possibilities(pattern, best, canidate, used, target_size);
                canidate.pop_back();
                used[i] = false;
            }
        }

    }

    bool check(string pattern, string canidate){
        for(int i=1; i <= pattern.size(); i++){
            if(pattern[i-1] == 'I'){ // increasing case
                if(canidate[i] < canidate[i-1]) return false;   // if not increasing doesnt match
            } else { // decreasing case
                if(canidate[i] > canidate[i-1]) return false; // if not decreasing doesnt match
            }
        }
        return true;
    }
};
