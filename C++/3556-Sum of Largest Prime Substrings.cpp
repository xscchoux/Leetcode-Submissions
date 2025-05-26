class Solution {
public:
    // from geeksforgeeks
    bool isPrime(long long n) {
    
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
        for (long long i = 5; i <= sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    long long sumOfLargestPrimes(string s) {
        set<long long, greater<>> allNum;
        for (int i=0; i<s.size(); i++) {
            for (int j=i; j<s.size(); j++) {
                string newString = s.substr(i, j-i+1);
                long long newNum = stol(newString);
                if (isPrime(newNum)) {
                    allNum.insert(newNum);
                }
            }
        }
        
        long long res = 0;
        int cnt = 0;

        for (auto it = begin(allNum); it != end(allNum); it++) {
            res += *it;
            if (++cnt == 3) break;
        }

        return res;
    }
};