const int kMod = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        for (int i=1; i<=n; i++) {
            int binaryLength = log2(i)+1;
            res = (res<<binaryLength)|i;
            res %= kMod;
        }

        return res;
    }
};


// Better
const int kMod = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0, binaryLength = 0;
        for (int i=1; i<=n; i++) {
            if ((i&(i-1)) == 0) binaryLength++;
            res = (res<<binaryLength)|i;
            res %= kMod;
        }

        return res;
    }
};