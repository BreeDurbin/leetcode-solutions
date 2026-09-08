class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        
        for(auto num : nums){
            sum = (sum + decode(num)) % MOD;
        }

        return (int) sum;
    }

    long long decode(long long num){
        int width = num % 10;
        long long d = floor(num / 10);

        int digit_count = to_string(d).size();

        int y_count = digit_count - width; // the 1 is the width of width

        // deconstruct d
        vector<int> y_digits, x_digits;
        
        while(d){
            if(y_count){
                y_digits.push_back(d % 10);
                y_count--;
            }
            else {
                x_digits.push_back(d % 10);
            }
            d /= 10;
        }

        // fix reverse ordering of x_count and y_count
        reverse(x_digits.begin(), x_digits.end());
        reverse(y_digits.begin(), y_digits.end());

        //reconstruct x and y       
        int x = 0, y = 0;

        for(auto num : x_digits){
            x = x * 10 + num;
        }

        for(auto num : y_digits){
            y = y * 10 + num;
        }
        
        cout << "x " << x << " y " << y << endl;
        
        return modPow(x, y); 
    }

    long long modPow(long long x, long long y) {
        long long result = 1;

        while (y > 0) {
            if (y & 1)
                result = result * x % MOD;

            x = x * x % MOD;
            y >>= 1;
        }

        return result;
    }

};
