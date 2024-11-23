class Solution {
public:
    bool isPrime(int num) {
        if (num <=2 || num%2 == 0) return num == 2;
        for (int i=3; i<sqrt(num+1); i++) {
            if (num%i == 0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if (n >= 8 && n <= 11) return 11;  // edge case: 11 is the only prime palindrome with two digits
        int N = to_string(n).size();
        int half = N/2, lhs = pow(10, half);

        while (true) {
            // Prime palindromes have odd digits except 11. Create odd-length palindromes only
            string lhsString = to_string(lhs);
            string rhsString = string(rbegin(lhsString), rend(lhsString)).substr(1);
            int curr = stoi(lhsString + rhsString);
            if (curr >= n && isPrime(curr)) {
                return curr;
            }
            lhs++;
        }

        return 0;
    }
};