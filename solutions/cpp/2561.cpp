class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        //initialize frequency map and get min element
        unordered_map<int, int> totals;
        int smallest_cost = INT_MAX;
        for (int b1 : basket1) {
            totals[b1]++;
            smallest_cost = min(smallest_cost, b1);
        }
        for (int b2 : basket2) {
            totals[b2]--;
            smallest_cost = min(smallest_cost, b2);
        }

        //feasability and generate to_swap list
        vector<int> to_swap;
        for(auto & [cost, freq] : totals){
            if(freq % 2 != 0) return -1;
            for(int i=0; i<abs(freq)/2; i++)to_swap.push_back(cost);
        }

        sort(to_swap.begin(), to_swap.end());

        long long cost = 0;
        int indirect_swap_cost = 2 * smallest_cost;

        for(int i=0; i<to_swap.size() / 2; i++){
            cost += min(to_swap[i], indirect_swap_cost);
        }

        return cost;
    }
};
