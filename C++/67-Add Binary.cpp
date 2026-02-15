class Solution {
public:
    string addBinary(string a, string b) {

        int idx1 = a.size()-1, idx2 = b.size()-1, carry = 0;
        string res = "";
        
        while (idx1 >= 0 || idx2 >= 0 || carry) {
            if (idx1 >= 0) {
                carry += a[idx1--]-'0';
            }
            if (idx2 >= 0) {
                carry += b[idx2--]-'0';
            }

            res += (carry%2+'0');
            carry = carry/2;
        }

        reverse(begin(res), end(res));
        return res;
    }
};