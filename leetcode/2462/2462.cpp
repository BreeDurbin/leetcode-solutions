class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if(costs.size()==1) return costs[0];
        priority_queue<int, vector<int>, greater<int>> first_candidates;
        priority_queue<int, vector<int>, greater<int>> last_candidates;
        long long ans = 0;
        int n = costs.size();


        int min_first_count=0,min_last_count=0;

        for(int i=1; i<=candidates; i++){
            // break if we overlap
            if(i-1 >= n-i) break;
            first_candidates.push(costs[i-1]);
            min_first_count = i;
            last_candidates.push(costs[n-i]);
            min_last_count = n-1-i;
        }


        bool is_overlapped = 0;

        for(int i=0; i<k; i++){
            //all indexes have been added to one of the pqs
            if(min_first_count > min_last_count) is_overlapped = 1;
            
            int min_first = !first_candidates.empty() ? first_candidates.top() : INT_MAX;
            int min_last = !last_candidates.empty() ? last_candidates.top() : INT_MAX;
            if(min_first <= min_last){
                ans+=min_first;
                first_candidates.pop();

                if(!is_overlapped){
                    first_candidates.push(costs[min_first_count]);
                    min_first_count++;
                }
            } else {
                ans+=min_last;
                last_candidates.pop();
                if(!is_overlapped){
                    last_candidates.push(costs[min_last_count]);
                    min_last_count--;
                }
            }
        }

        return ans;
        
    }
};