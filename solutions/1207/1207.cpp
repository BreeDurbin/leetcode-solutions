class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> map;
        for(auto& num : arr){
            map[num]++;
        }

        unordered_set<int> s;
        for(auto [key, value] : map){
            s.insert(value);
        }

        return map.size() == s.size();
    }
};