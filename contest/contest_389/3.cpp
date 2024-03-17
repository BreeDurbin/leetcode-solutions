class Solution {
public:
    int minimumDeletions(string word, int k) {
        int k_over_2 = k/2;
        unordered_map<char, int> map;
        int n = word.size();
        
        for(int i=0; i<n; i++){
            map[word[i]]++;
        }
        
        vector<int> counts;
        for (auto i = map.begin(); i != map.end(); i++){
            counts.push_back(i->second);
        }
        
        if(counts.size() == 1) return 0;
        
        sort(counts.begin(), counts.end(),  std::greater<>());
        
        int ans = 0;
        for(int i=0, j=counts.size()-1; i<j; i++, j--){
            if(counts[i] - counts[j] > k) ans += counts[i] - counts[j] - k;
        }
        
        return ans;
    }
};