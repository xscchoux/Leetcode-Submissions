class Solution {
public:
    bool isOK(vector<int>& candies, long long k, int target) {
        long long piles = 0;
        for (int c:candies) {
            piles += c/target;
            if (piles >= k) return true;
        }
        return piles >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long tot = accumulate(begin(candies), end(candies), 0LL);
        if (tot/k == 0) return 0;
        int left = 1, right = tot/k;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(candies, k, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(candies, k, right)) {
            return right;
        }
        return left;
    }
};