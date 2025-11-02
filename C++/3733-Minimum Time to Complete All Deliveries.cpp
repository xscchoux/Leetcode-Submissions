class Solution {
public:
    int lcm;
    bool isOK(long long T, vector<int>& d, vector<int>& r) {
        long long cnt1 = T - (T/r[0]), cnt2 = T - (T/r[1]), shared = T - (T/r[0]) - (T/r[1]) + (T/lcm); // shared: hours that both delivery drones can deliver
        long long d1 = d[0], d2 = d[1];
        cnt1 -= shared;
        cnt2 -= shared;
        d1 = max(0LL, d1-cnt1);
        d2 = max(0LL, d2-cnt2);

        return d1 + d2 <= shared;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long left = 1, right = 6e13;
        this->lcm = r[0]*r[1]/__gcd(r[0], r[1]);

        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(mid, d, r)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(left, d, r)) {
            return left;
        }
        return right;

    }
};