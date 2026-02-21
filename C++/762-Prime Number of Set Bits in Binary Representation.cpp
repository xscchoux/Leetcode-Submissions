class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
        int res = 0;
        
        for (int i=left; i<=right; i++) {
            int bits = __builtin_popcount(i);
            if (s.contains(bits)) {
                res++;
            }
        }
        return res;
    }
};