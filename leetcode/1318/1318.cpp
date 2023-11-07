class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip_count = 0;
        for(int i=0; i<32; i++){
            int a_bit = a & 1;
            a >>= 1;
            int b_bit = b & 1;
            b >>= 1;
            int c_bit = c & 1;
            c >>= 1;
            //cout << "abit " << a_bit << " bbit" << b_bit << " cbit" << c_bit << endl;
            if(c_bit == 0) flip_count+= a_bit + b_bit;
            else if(a_bit == 0 && b_bit == 0) flip_count++;
        }
        return flip_count;
    }
};