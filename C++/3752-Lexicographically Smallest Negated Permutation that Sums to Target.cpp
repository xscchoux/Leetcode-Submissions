class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long mx, mn;
        mx = (long long)n*(n+1)/2;
        mn = -(long long)n*(n+1)/2;

        if (target > mx || target < mn) {
            return {};
        }

        long long diff = mx-target;
        if (diff%2) return {};

        vector<int> neg, pos;

        for (int i=n; i>=1; i--) {
            if (diff >= 1LL*2*i) {
                diff -= 1LL*2*i;
                neg.push_back(-i);
            } else {
                pos.push_back(i);
            }
        }

        // no need to sort, just combine to vectors
        for (int i=pos.size()-1; i>=0; i--) {
            neg.push_back(pos[i]);
        }

        return neg;
    }
};