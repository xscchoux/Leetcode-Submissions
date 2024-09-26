using LL = long long;
class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        k -= 1;
        while ( k > 0 ){
            LL start = res, end = res + 1;  // start and end can be very large in the while loop
            int count = 0;
            while (start <= n){
                count += min((LL)n+1, end) - start;
                start *= 10;
                end *= 10;
            }
            if ( k >= count ){
                k -= count;
                res++;
            } else {
                k--;
                res *= 10;
            }
        }
        return res;
    }
};


// digit prefix count
// https://github.com/wisdompeak/LeetCode/tree/master/Others/440.K-th-Smallest-in-Lexicographical-Order
using LL = long long;
class Solution {
public:
    int countSuffix(int prefix, int n) {
        int count = 0;
        LL exp = 10;
        while (true) {
            LL lower = prefix*exp, upper = prefix*exp + exp - 1;
            if (lower > n) break;
            else if (n >= lower && n <= upper) {
                count += n-lower+1;
            } else {
                count += exp;
            }
            exp *= 10;
        }

        return count;
    }
    int findKthWithPrefix(int prefix, int n, int k) {
        if (k > 0) {
            int start = (prefix==0)?1:0;
            for (int i=start; i<=9; i++) {
                int count = 1 + countSuffix(prefix*10+i, n);
                if (count < k) {
                    k -= count;
                } else {
                    return findKthWithPrefix(prefix*10+i, n, k-1);
                }
            }
        }
        return prefix; // when k == 0
    }
    int findKthNumber(int n, int k) {
        return findKthWithPrefix(0, n, k);
    }
};