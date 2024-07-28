class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n);
        for(int i=0; i<n; i++){
            vector<string> temp = getSubstrings(arr[i]);
            for(auto& a : temp){
                bool uncommon = true;
                for(int j=0; j<n; j++){
                    if(i==j) continue;
                    if(arr[j].find(a) != string::npos){
                        uncommon = false;
                    }
                }
                if(uncommon){
                    //add in a if it is lexocographically less than the current string in ans[i]
                    // or it ans[i] == ""
                    if(ans[i] == "" || a.length() < ans[i].length()
							|| (a.length() == ans[i].length() && a.compare(ans[i]) < 0)){
                        ans[i] = a;
                    }
                }
            }
        }
        return ans;
    }
    
    vector<string> getSubstrings(string str){
        vector<string> ans;
        for(int i=0; i<str.size(); i++){
            string temp = "";
            for(int j=i; j<str.size(); j++){
                temp += str[j];
                ans.push_back(temp);
            }
        }
        return ans;
    }
};