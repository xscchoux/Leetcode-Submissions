vector<int> SieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    vector<int> res;
    for (int p=2; p<=n; p++)
       if (prime[p])
           res.push_back(p);
    return res;
}

vector<int> primes = SieveOfEratosthenes(100000);

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    void uni(int a, int b, vector<int>& parent) {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb) parent[pa] = pb;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, vector<int>> hmap;
        vector<int> parent(N);
        for (int i=0; i<N; i++) {
            parent[i] = i;
        }
        
        for (int i=0; i<N; i++) {
            int tmp = nums[i];
            for (int p:primes) {
                if (p*p > tmp) break;
                if (tmp%p == 0) {
                    while (tmp%p == 0) tmp = tmp/p;
                    hmap[p].push_back(i);
                }
            }
            if (tmp == 1) continue;
            hmap[tmp].push_back(i);
        }
        
        for (auto &kv:hmap) {
            for (int i=1; i<kv.second.size(); i++) {
                uni(kv.second[i-1], kv.second[i], parent);
            }
        }

        for (int i=1; i<N; i++) {
            if (find(i-1, parent) != find(i, parent)) {
                return false;
            }
        }
        
        return true;
    }
};