class Solution {
public:
    int count = 0;

    int countArrangement(int n) {
        // generate all permutations
        //for each permutation count++ if
        // perm[i] % i == 0
        // OR i % perm[i] == 0
        vector<bool> visited(n+1);
        solve(n, 1, visited);
        return count;
    }

    void solve(int n, int pos, vector<bool> visited){
        if(pos > n) count++;
        for(int i=1; i<=n; i++){
            if(!visited[i] && (isBeautiful(i, pos) || isBeautiful(pos,i))){
                visited[i] = true;
                solve(n, pos+1, visited);
                visited[i] = false;
            }
        }
    }
    
    bool isBeautiful(int i, int j){
        return (i%j==0) || (j%i==0);
    }
};