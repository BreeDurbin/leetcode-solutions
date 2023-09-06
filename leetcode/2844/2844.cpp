class Solution {
public:
    int minimumOperations(string nums) {
        if(nums.size() == 1){
            if(nums[0] == 0) return 0;
            else return 1;
        }
        if(nums.size() == 2){
            //if(nums[0] == '3' && nums[1] == '0') return 1;
            if(nums[0] == '2' && nums[1] == '5') return 0;
            if(nums[0] == '2'){
                if(nums[1] == '0') return 1;
                else return 2;
            }
            if(nums[0] == '1'){
                if(nums[1] == '0') return 1;
                else return 2;
            }
        }
        bool found_five = false, found_zero = false, found_exact = false;
        int ops = 0;
        for(int i=nums.size()-1; i>=0;i--){
            ops++;
            cout << ops << endl;

            if(found_five && (nums[i] == '2' || nums[i] == '7')){
                cout << "break on " << nums[i] << endl;
                found_exact = true;
                break;
            }
            if(found_zero &&(nums[i] == '0' || nums[i] == '5')){
                cout << "break on " << nums[i] << endl;
                found_exact = true;
                break;
            }
            if(!found_five && nums[i] == '5'){
                found_five = true;
                cout << "found_five" << endl;
                continue;
            }
            else if(!found_zero && nums[i] == '0'){
                found_zero = true;
                cout << "found_zero" << endl;
                continue;
            }
        }
        cout << ops << endl;
        
        if(found_exact){
            return ops - 2;
        }
        else if(found_zero){
            return ops - 1;
        }
        
        return ops;
    }
};