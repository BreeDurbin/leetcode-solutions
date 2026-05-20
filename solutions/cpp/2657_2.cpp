class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> pca(n, 0);

        unordered_map<int, int> A_map, B_map;


        // i = 0 case here
        A_map[A[0]]++;
        B_map[B[0]]++;
        if(A[0] == B[0]) pca[0]++;

        // i to n case
        for(int i=1; i<n; i++){
            A_map[A[i]]++;
            B_map[B[i]]++;
            //count common numbers for pca[i]

            int increase = 0;
            if(A[i] == B[i]) increase++;
            else{
                if(B_map.find(A[i]) != nullptr) increase++;
                if(A_map.find(B[i]) != nullptr) increase++;
            }

            pca[i] = pca[i-1] + increase;
        }

        return pca;
    }
};
