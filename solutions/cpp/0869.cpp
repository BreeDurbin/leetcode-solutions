class Solution {
public:
    bool reorderedPowerOf2(int n){

        unordered_set<string> powers_of_two;

        for(long i=1; i <= INT_MAX; i *= 2){
            string s = int_to_sorted_string(i);
            powers_of_two.insert(s);
        }

        string sorted_n = int_to_sorted_string(n);

        return powers_of_two.find(sorted_n) != powers_of_two.end();
    }

    string int_to_sorted_string(int i){
        vector<int> v;

        while(i){
            v.push_back(i % 10);
            i /= 10;
        }

        sort(v.begin(), v.end());

        string s = "";

        for(int i=0; i<v.size(); i++){
            s += to_string(v[i]);
        }

        return s;
    }
};
