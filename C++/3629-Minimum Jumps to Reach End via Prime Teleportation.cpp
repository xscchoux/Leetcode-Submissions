// O(NlogN), NlogN for filling `primeToIdx`, the BFS part is O(N)
vector<int> sieve_simple(int n) {
    if (n < 2) return {};
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    int limit = sqrt(n);
    for (int p = 2; p <= limit; ++p) {
        if (!is_prime[p]) continue;
        for (long long x = 1LL*p*p; x <= n; x += p)
            is_prime[x] = false;
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) if (is_prime[i]) primes.push_back(i);
    return primes;
}
vector<int> primes = sieve_simple(1e6);


class Solution {
public:
    int minJumps(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, vector<int>> primeToIdx;
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            for (int p : primes) {
                if (1LL * p * p > num) break;
                if (num % p == 0) {
                    primeToIdx[p].push_back(i);
                    while (num % p == 0) num /= p;
                }
            }
            if (num > 1) {
                primeToIdx[num].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> visited(N, false);
        visited[0] = true;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [curr, step] = q.front();
                if (curr == N-1) return step;
                q.pop();

                if (primeToIdx.contains(nums[curr])) {
                    for (int nxtIdx:primeToIdx[nums[curr]]) {
                        if (nxtIdx == curr || visited[nxtIdx]) continue;
                        visited[nxtIdx] = true;
                        q.push({nxtIdx, step+1});
                    }
                    primeToIdx.erase(nums[curr]);
                }

                if (curr + 1 < N && !visited[curr+1]) {
                    visited[curr+1] = true;
                    q.push({curr+1, step+1});
                }
                if (curr - 1 >= 0 && !visited[curr-1]) {
                    visited[curr-1] = true;
                    q.push({curr-1, step+1});
                }
            }
        }

        return -1;
    }
};