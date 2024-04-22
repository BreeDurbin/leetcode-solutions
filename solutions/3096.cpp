class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size(), bob = 0;
        
        for(auto &p : possible){
            if(p==0) p = - 1;
            bob += p;
        }
        
        int alice = 0;
        for(int i=0; i<n-1; i++){
            alice += possible[i];
            bob -= possible[i];
            if(alice > bob){
                return i + 1;
            }
        }
        
        return -1;
    }
};