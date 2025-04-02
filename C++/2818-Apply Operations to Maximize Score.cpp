using LL = long long;
vector<int> sieve_of_eratosthenes(int limit) {
    vector<int> primes;
    vector<int> visited(limit+1, false);
    visited[0] = visited[1] = true;

    for (int i=2; i<=limit; i++) {
        if (!visited[i]) {
            primes.push_back(i);
            for (LL multiple = (LL)i*i; multiple <= limit; multiple+=i) {
                visited[multiple] = true;
            }
        }
    }
    return primes;
}

vector<int> allPrimes = sieve_of_eratosthenes(1e5);

class Solution {
public:
    LL powWithMod(LL a, int b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        const int kMod = 1e9+7, N = nums.size();
        vector<int> distinct(N);  // number of distinct primes in nums[i]
        for (int i=0; i<N; i++) {
            int curr = nums[i];
            for (int p:allPrimes) {
                if (p*p > curr) break;
                if (curr%p == 0) {
                    while (curr%p == 0) {
                        curr /= p;
                    }
                    distinct[i]++;
                }
            }
            if (curr > 1) distinct[i]++;
        }

        vector<int> left(N, -1), right(N, N);
        stack<int> stk;  // monotonically decreasing stack
        for (int i=0; i<N; i++) {
            while (!stk.empty() && distinct[stk.top()] < distinct[i]) {
                int prevIdx = stk.top();
                stk.pop();
                right[prevIdx] = i;
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        vector<pair<int, LL>> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({nums[i], (long long)(right[i]-i)*(i-left[i])});
        }


        LL res = 1;
        sort(begin(arr), end(arr), greater<>());

        for (auto &[val, cnt]:arr) {
            if (cnt <= k) {
                k -= cnt;
                res = (res*powWithMod(val, cnt, kMod))%kMod;
                if (k == 0) return res;
            } else {
                return res*powWithMod(val, k, kMod)%kMod;
            }
        }

        return res;
    }
};
