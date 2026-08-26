class Solution {
public:

    struct Query {
        int l;
        int r;
        int i;
    };

    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {

        // map queries into a vector<Query>
        vector<Query> mapped_queries(queries.size());

        for(int i=0; i<queries.size(); i++){
            mapped_queries[i].l = queries[i][0];
            mapped_queries[i].r = queries[i][1];
            mapped_queries[i].i = i;
        } 

        return Mo_Algorithm(nums, mapped_queries, k, sqrt(nums.size()));
    }

    vector<bool> Mo_Algorithm(vector<int>& nums, vector<Query>& queries, int k, int block_size){

        sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b) {
            if (a.l / block_size != b.l / block_size)
                return a.l / block_size < b.l / block_size;

            return a.r < b.r;
        });
                
        vector<bool> ans(queries.size(), false);

        unordered_map<int,int> f;
        int odd_count = 0;
        int distinct_count = 0;

        int cur_l = 0, cur_r = -1;

        for(auto query : queries){

            while(cur_l > query.l){
                cur_l--;
                add(f, nums[cur_l], odd_count, distinct_count);
            }

            while(cur_r < query.r){
                cur_r++;
                add(f, nums[cur_r], odd_count, distinct_count);
            }

            while (cur_l < query.l) {
                remove(f, nums[cur_l], odd_count, distinct_count);
                cur_l++;
            }

            while(cur_r > query.r){
                remove(f, nums[cur_r], odd_count, distinct_count);
                cur_r--;
            }

            ans[query.i] = distinct_count == k && odd_count == 0;
        }

        return ans;
    }

    void add(unordered_map<int, int>& f, int val, int& odd_count, int& distinct_count) {
        if (f[val] % 2 == 1) odd_count--;
        else odd_count++;
        f[val]++;
        if (f[val] == 1) distinct_count++;
    }

    void remove(unordered_map<int, int>& f, int val, int& odd_count, int& distinct_count) {
        if (f[val] % 2 == 1) odd_count--;
        else odd_count++;
        f[val]--;
        if (f[val] == 0) distinct_count--;
    }
};
