class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.size();

        for(int i=0; i<n;){
            int j=0;
            while(j<n){
                if(j+1<n && word[j]==word[j+1]) ans += 1;
                j++;
            }
            i=j;
        }
        

        return ans;
    }
};
