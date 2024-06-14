class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        int a=0, b=1;
        int c, d;
        char ch;
        while (ss >> c >> ch >> d) {
            int num = a*d + b*c;
            int den = b*d;
            int gcd = abs(__gcd(num, den));
            a = num/gcd;
            b = den/gcd;
        }

        return to_string(a) + "/" + to_string(b);
    }
};