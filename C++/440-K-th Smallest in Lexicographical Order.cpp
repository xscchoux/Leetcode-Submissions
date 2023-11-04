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