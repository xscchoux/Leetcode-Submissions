class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int kMod = 1e9+7;
        for (int i = n-1; i>=0; i--){
            bool isOneA = (1L<<i)&a;  // long is typically at least 64 bits in size, so it can handle i up to 63 without issue.
            bool isOneB = (1L<<i)&b;
            if (isOneA && isOneB) continue;
            else if (!isOneA && !isOneB) {
                a |= 1L<<i;
                b |= 1L<<i;
            }
            else {
                long long tmpA = a & (~(1L<<i)); // make the ith from 1 to 0
                long long tmpB = b & (~(1L<<i));
                if (tmpA >= tmpB) {
                    b = tmpB | (1L<<i);
                    a = tmpA;
                } else {
                    a = tmpA | (1L<<i);
                    b = tmpB;
                }
            }
        }
        return (a%kMod)*(b%kMod)%kMod;
    }
};