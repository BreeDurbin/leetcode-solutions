class Solution {
public:
    int minOperations(int k) {
        int size = 1, count = 1, ans=0;
        bool flag = false;
        while(size*count < k){
            if(flag){
                count++;
                flag=false;
            }
            else{
                size++;
                flag=true;
            }
            ans++;
        }
        return ans;
    }
};