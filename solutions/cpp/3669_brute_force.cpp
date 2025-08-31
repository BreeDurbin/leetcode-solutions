class Solution {
public:
    vector<int> minDifference(int n, int k) {
        auto divisors = get_divisors(n);

        vector<int> ans, picked;
        return backtrack(0, k, 1, n, picked, divisors);;
    }

    vector<int> backtrack(int i, int k, long long cur_product, int target_product, vector<int>& picked, vector<int>& divs){
        if(picked.size() == k && cur_product == target_product) return picked;
        if(i >= divs.size() || cur_product > target_product || picked.size() == k) return {};

        //dont pick 
        vector<int> ans1 = backtrack(i+1, k, cur_product, target_product, picked, divs);
        //pick
        long long new_product = cur_product * divs[i];
        picked.push_back(divs[i]);
        vector<int> ans2 = backtrack(i, k, new_product, target_product, picked, divs);
        picked.pop_back();

        // return best result of pick and not pick
        if(ans1.size() != k) return ans2;
        if(ans2.size() != k) return ans1;
        int ans1_diff = *max_element(ans1.begin(), ans1.end())  - *min_element(ans1.begin(), ans1.end());
        int ans2_diff = *max_element(ans2.begin(), ans2.end())  - *min_element(ans2.begin(), ans2.end());
        return ans1_diff < ans2_diff ? ans1 : ans2;
    }

    vector<int> get_divisors(int n){
        int half_n = (n/2)+1;

        unordered_set<int> divs;
        
        for(int i=1; i<half_n; i++){
            if(n%i == 0){
                divs.insert(i);
                divs.insert(n/i);
            }
        }

        vector<int> ans;
        ans.reserve(divs.size());
        for (auto it = divs.begin(); it != divs.end(); ) {
            ans.push_back(move(divs.extract(it++).value()));
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
