class Solution {
public:
    bool isPrime(int n) {
    
        // Check if n is 1 or 0
        if (n <= 1)
            return false;

        // Check if n is 2 or 3
        if (n == 2 || n == 3)
            return true;

        // Check whether n is divisible by 2 or 3
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        
        // Check from 5 to square root of n
        // Iterate i by (i+6)
        for (int i = 5; i *i<=n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        int N = s.size();
        // forward
        int curr = 0;
        for (int i=0; i<N; i++) {
            curr = curr*10 + (s[i]-'0');
            if (!isPrime(curr)) return false;
        }

        // backward
        curr = 0;
        for (int i=N-1; i>=0; i--) {
            curr = curr + (s[i]-'0')*pow(10, N-1-i);
            if (!isPrime(curr)) return false;
        }

        return true;
    }
};