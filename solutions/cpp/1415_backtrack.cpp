class Solution {
public:
    vector<char> chars = {'a', 'b', 'c'};

    string getHappyString(int n, int k) {
        vector<string> canidates;
        string canidate = "";

        generate_happy_strings(canidates, canidate, 0, n);

        sort(canidates.begin(), canidates.end());

        cout << "sz " << canidates.size() << endl;

        return canidates.size() < k ? "" : canidates[k-1];
    }

    void generate_happy_strings(vector<string>& canidates, string& canidate, int index, int n){
        if(canidate.size() == n){
            canidates.push_back(canidate);
            return;
        }

        for(char c : chars){
            if(index == 0 || canidate[index-1] != c){
                canidate.push_back(c);
                generate_happy_strings(canidates, canidate, index + 1, n);
                canidate.pop_back();
            }
        }
    }
};
