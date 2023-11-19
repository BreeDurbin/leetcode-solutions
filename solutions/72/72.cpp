class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word1 == word2) return 0;
        return editDistance(word1, word2);
    }

    int editDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> cache(n+1, vector<int>(m+1));  

        for(int j=0; j<m; j++){
            cache[n][j] = m-j;
        }

        for(int i=0; i<n; i++){
            cache[i][m] = n-i;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(word1[i] == word2[j]) cache[i][j] = cache[i+1][j+1];
                else{
                    int replaceCost = 1+cache[i+1][j+1];
                    int insertCost = 1+cache[i+1][j];
                    int deleteCost = 1+cache[i][j+1];
                    cache[i][j] = min(replaceCost, min(insertCost, deleteCost));
                }
            }
        }

        return cache[0][0];
    }

};