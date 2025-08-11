class Solution {
public:

    int MOD = 1'000'000'007;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        int i = n;
        int cur_pow = 1;

        // build pows array
        while(i > 0){
            if(i & 1) pows.push_back(cur_pow);
            cur_pow *= 2;
            i /= 2;
        }

        // run queries
        vector<int> ans;
        for(auto& query : queries){
            long long product = 1;
            for(int i = query[0]; i <= query[1]; i++){
                product = (product * pows[i]) % MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }

};
