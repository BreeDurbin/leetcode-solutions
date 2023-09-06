class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
        //cout << "array size: " << n <<  " target: " << target << endl;
        
        long long sum = 0;
        int i = 1;
        int j = target - 1;
        int ctr = 0;
        while(ctr < n){
            
            if(j == i){
                //cout << "ctr: " << ctr <<  " nums: " << i << endl;
                if(target%2 == 0){
                    sum += i;
                    ctr++;
                }
                i = target;
                continue;
            }
            
            //cout << "ctr: " << ctr <<  " nums: " << i << endl;
            sum += i;
            i++;
            if(i < j) j--;
            ctr++;
            

            

        }
        
        return sum;
        
        
        
    }
};