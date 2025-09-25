class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res = "";
        if ((numerator < 0)^(denominator < 0)) res += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        if (num%den == 0) {
            return res + to_string(num/den);
        }

        long long remainder = num%den;
        res += to_string(num/den) + ".";
        unordered_map<int, int> pos;

        while (remainder) {
            if (pos.contains(remainder)) {
                res.insert(pos[remainder], "(");
                res.push_back(')');
                break;
            }
            pos[remainder] = res.size();
            remainder *= 10;
            int q = remainder/den;
            remainder = remainder%den;
            res.push_back(q + '0');
        }

        return res;
    }
};