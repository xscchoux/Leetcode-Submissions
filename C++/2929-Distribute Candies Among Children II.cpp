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


// inclusion-exclusion principle, O(1)
class Solution {
public:
    long long H(int n) {  // H(3, n) = C(n+2, n) = C(n+2, 2)
        if (n < 0) return 0;

        return (long long)(n+2)*(n+1)/2;
    }
    long long distributeCandies(int n, int limit) {
        return H(n) - 3*H(n-(limit+1)) + 3*H(n-2*(limit+1)) - H(n-3*(limit+1));
    }
};