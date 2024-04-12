class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int real1 = 0, imag1 = 0, real2 = 0, imag2 = 0;
        sscanf(num1.c_str(), "%d+%di",&real1,&imag1);
        sscanf(num2.c_str(), "%d+%di",&real2,&imag2);
        
        //cout << "r1 " << real1 << " r2 " << real2 << endl;
        //cout << "i1 " << imag1 << " i2 " << imag2 << endl;
        
        int real = real1 * real2 - imag1 * imag2;
        int imag = real1 * imag2 + real2*imag1;
        
        return to_string(real) + '+' + to_string(imag) + 'i';
    }
};