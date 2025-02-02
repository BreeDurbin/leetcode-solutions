class Solution {
public:

    int maxDistance(string s, int k) {
        int ans = 0, m = s.size();
        int up = 0, down = 0, left = 0, right = 0;
        int horiz = 0, vert = 0;

        for(int i=0; i<m; i++){
            if(s[i] == 'N'){
                up++;
                vert++;
            }
            if(s[i] == 'S'){
                down++;
                vert--;
            }
            if(s[i] == 'E'){
                right++;
                horiz++;
            }
            if(s[i] == 'W'){
                left++;
                horiz--;
            }
            int min_horiz = min(left, right);
            int min_vert = min(up, down);

            ans = max(ans, abs(horiz) + abs(vert) + 2*min(k, min_horiz + min_vert));
        }

        return ans;
    }

};
