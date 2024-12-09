using PII = pair<int, int>;

bool calculated = false;
unordered_set<int> primes;
unordered_set<int> getPrimes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    unordered_set<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.insert(i);
        }
    }
    return primes;
}


class Solution {
public:
    Solution () {
        if (!calculated) {
            calculated = true;
            primes = getPrimes(10000);
        }
    }
    int minOperations(int n, int m) {
        if (primes.contains(n) || primes.contains(m)) return -1;
        int digit = floor(log10(n) + 1);
        vector<bool> visited(1e4+1, false);
        
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({n, n});
        int res = INT_MAX;

        while (!pq.empty()) {
            int length = pq.size();
            while (length-- > 0) {
                auto [val, curr] = pq.top();
                pq.pop();
                if (visited[curr]) continue;
                if (curr == m) {
                   return val;
                }
                visited[curr] = true;

                string numString = to_string(curr);
                for (int i=0; i<numString.size(); i++) {
                    if (numString[i] != '0') {
                        numString[i] -= 1;
                        int num1 = stoi(numString);
                        if (num1 > 0 && floor(log10(num1) + 1) == digit && !visited[num1] && primes.find(num1) == primes.end()) {
                            pq.push({val + num1, num1});
                        }
                        numString[i] += 1;
                    }

                    if (numString[i] != '9') {
                        numString[i] += 1;
                        int num2 = stoi(numString);
                        if (!visited[num2] && primes.find(num2) == primes.end()) {
                            pq.push({val + num2, num2});
                        }
                        numString[i] -= 1;
                    }                    
                }
            }
        }

        return -1;
    }
};