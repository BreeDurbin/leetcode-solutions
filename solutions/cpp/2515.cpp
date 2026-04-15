class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        int ans = -1;

        for(int i=0; i<n; i++){
            int next = (startIndex + i) % n;
            if(words[next] == target){
                cout << " setting ans: " << i << endl;
                ans = i;
                break;
            }
        }

        for(int i=0; i<n; i++){
            int next = (startIndex - i + n) % n;
            if(words[next] == target){
                cout << "setting ans: i - " << i << " current ans " << ans << endl; 
                ans = ans == -1 ? i : min(ans, i);
                break;
            }
        }

        return ans;
    }
};
