class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto &spell : spells){

            ans.push_back(
                potions.end() - lower_bound(
                    potions.begin(), 
                    potions.end(), 
                    spell, 
                    [success](int spell, int potion){return (long long)spell * (long long)potion < success;})
                );
        }
        return ans;
    }
};