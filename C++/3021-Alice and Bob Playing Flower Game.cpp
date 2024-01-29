using LL = long long;
class Solution {
public:
    // When x + y is odd
    long long flowerGame(int n, int m) {
        LL res = 0;
        for (int i=1; i<=n; i++) {
            if (i%2 == 1) res += m/2;
            else res += (m+1)/2;
        }
        return res;
    }
};