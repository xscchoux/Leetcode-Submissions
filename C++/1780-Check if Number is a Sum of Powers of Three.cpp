// First AC
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int left = 0, right = n;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (pow(3, mid) <= n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int mx;
        if (pow(3, right) <= n) {
            mx = right;
        } else {
            mx = left;
        }

        while (mx >= 0) {
            if (n >= pow(3, mx)) n -= pow(3, mx);
            mx--;
        }

        return n == 0;
    }
};


// best solution
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n%3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};