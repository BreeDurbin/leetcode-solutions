class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long swaps = 0;
        int current = n-1;
        for(int target=n-1; target>=0; target--){
            if(s[target] == '1'){
                swaps+=current-target;
                current--;
            }
        }
        
        return swaps;
    }
    
    
};