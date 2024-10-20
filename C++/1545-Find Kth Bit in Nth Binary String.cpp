class Solution {
public:
    char findKthBit(int n, int k) {
        int flips = 0;
        while (k != 1) {
            if ((k&(k-1)) == 0) return (flips%2)?'0':'1';
            int diff = k - pow(2, (int)log2(k));
            flips++;
            k -= 2*diff;
        }

        if (flips%2) return '1';
        return '0';
    }
};