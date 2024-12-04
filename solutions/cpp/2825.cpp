class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0, m = str1.size(), j=0, n=str2.size();
        
        while(i < m && j < n){
            if(str1[i] == str2[j] || str1[i] == str2[j]
                || str1[i] + 1 == str2[j]
                || (str1[i] == 'z' && str2[j] == 'a') 
            ){
                j++;
            }
            i++;
        }

        return j == n;
    }
};
