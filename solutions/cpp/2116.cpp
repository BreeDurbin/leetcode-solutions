class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 == 1) return false;

        int open = 0, closed = 0, wildcard = 0;
        for(int i=0; i<n; i++){
            if(locked[i] == '0'){ 
                wildcard++;
                continue;
            }
            if(s[i] == '('){
                open++;
            }
            if(s[i] == ')'){
                closed++;
            }
            if(open - closed < 0){
                if(wildcard <= 0) return false;
                wildcard--;
                open++;
            }
        }

        open = 0, closed = 0, wildcard = 0;
        for(int i=n-1; i >= 0; i--){
            if(locked[i] == '0'){ 
                wildcard++;
                continue;
            }
            if(s[i] == '('){
                open++;
            }
            if(s[i] == ')'){
                closed++;
            }
            if(closed - open < 0){
                if(wildcard <= 0) return false;
                wildcard--;
                closed++;
            }
        }

        return true;
    }
};
