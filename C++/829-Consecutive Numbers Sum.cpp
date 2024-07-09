class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int k = 2, res = 0;
        
        // S = n + (n+1) + ... + (n+k-1) = (2*n+k-1)*k/2
        // n = (2*S+k-k^2)/(2*k), n must be a positive integer
        
        while (true) {
            int tmp = 2*n + k - (k*k);
            if (tmp <= 0) break;
            if (tmp%(2*k) == 0) res++;
            k++;    
        }

        return res+1;
    }
};