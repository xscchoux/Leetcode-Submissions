using LL = long long;
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        LL res = 0;
        int firstMin = max(0, n-2*limit);
        int firstMax = min(limit, n);
        for (int first = firstMin; first<=firstMax; first++){
            int secondMin = max(0, n-first-limit);
            int secondMax = min(limit, n-first);
            res += (secondMax-secondMin+1);
        }
        return res;
    }
};