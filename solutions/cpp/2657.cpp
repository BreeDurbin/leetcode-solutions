class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> a,b;
        vector<int> ans(n, 0);
        a.insert(A[0]);
        b.insert(B[0]);
        if(A[0] == B[0]) ans[0]++;

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1];
            a.insert(A[i]);
            b.insert(B[i]);
            if(A[i] == B[i]){
                ans[i]++;
                continue;
            }
            if(b.count(A[i])) ans[i]++;
            if(a.count(B[i])) ans[i]++;
        }

        return ans;
    }
};
