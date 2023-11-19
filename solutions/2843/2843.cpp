class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        //hi_sym = compute how many symmetric integers from 1 to high
        //lo_sym = compute how many symmettric integers from 1 to lo
        //result = hi_sym-lo_sym
        
        int ans = 0;
        for(int i=low; i<=high; i++){
            int digits=0,temp=i;
            while(temp>0){
                digits++;
                temp/=10;
            }
            if(digits%2) continue;

            temp=i;
            int s=0,l=0,r=0;
            while(s<(digits/2)){
                l+=temp%10;
                temp/=10;
                s++;
            }
            while(s<digits){
                r+=temp%10;
                temp/=10;
                s++;
            }
            if(l==r)ans++;

        }
        return ans;
    }
};
