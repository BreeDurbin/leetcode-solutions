
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> answer;
        int left = 0, right = products.size()-1;
        string prefix = "";

        for(int i=0; i<searchWord.size(); i++){
            while(left<=right && i <= products[left].size() && products[left][i] != searchWord[i]) left++;
            while(left<=right && i <= products[right].size() && products[right][i] != searchWord[i]) right--;
            vector<string> row;
            for(int j = 0; j < min(right - left + 1, 3); j++){
                cout << "j " << j << endl;
                row.push_back(products[left + j]);
            }
            answer.push_back(row);
        }

        return answer;
    }
};