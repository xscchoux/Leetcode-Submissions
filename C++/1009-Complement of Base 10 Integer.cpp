class Solution {
public:
    int bitwiseComplement(int n) {
        int base = 1, res = 0;
        
        do {
            if (n%2 == 0) {
                res += base;
            }
            n /= 2;
            base = base*2;
        } while (n > 0);

        return res;
    }
};