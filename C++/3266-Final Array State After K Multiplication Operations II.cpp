using LL = long long;
using PLI = pair<LL, int>;

class Solution {
public:
    int kMod = 1e9+7;
    LL powWithMod(LL a, int b) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int N = nums.size();
        unordered_set<int> indCount;
        priority_queue<PLI, vector<PLI>, greater<>> pq;

        for (int i=0; i<N; i++) {
            pq.push({nums[i], i});
        }

        // check if all indices are visited -> the cycle of operations begin
        // Note that we cannot put (multiplier*nums[i])%kMod in the priority queue. We need the real order of multiplied nums 
        while (k > 0 && indCount.size() != N) {
            auto [num, idx] = pq.top();
            pq.pop();
            indCount.insert(idx);
            pq.push({num*multiplier, idx});
            k--;
        }

        int q = k/N, r = k%N;
        int pow = powWithMod(multiplier, q);  

        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            num = num%kMod;
            pq.pop();
            if (r > 0) nums[idx] = ((LL)multiplier*(num*pow%kMod))%kMod;
            else nums[idx] = (num*pow)%kMod;
            r--;
        }

        return nums;
    }
};