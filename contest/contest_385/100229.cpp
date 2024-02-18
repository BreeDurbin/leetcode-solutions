class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0, m = arr1.size(), n = arr2.size();
        
        for(int i=0; i<m; i++){
            str1.push_back()
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int curr = 0;
                int left = arr1[i], right = arr2[j];
                stack<int> lefties, righties;
                while(left != 0){
                    lefties.push(left % 10);
                    left /= 10;
                }
                while(right != 0){
                    righties.push(right % 10);
                    right /= 10;
                }
                
                while(!lefties.empty() && !righties.empty()){
                    if(lefties.top() == righties.top()){
                        curr++;
                        lefties.pop();
                        righties.pop();
                    } else {
                        break;
                    }
                }
                
                ans = max(curr, ans);
            }
        }
        
        return ans;
        
    }
};