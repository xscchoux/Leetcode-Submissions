using LL = long long;
vector<vector<int>> getDivisor() {
    int N = 50001;
    vector<vector<int>> divisors(N);
    for (int i=1; i<N; i++) {
        for (int j=i; j<N; j+=i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

class Solution {
public:
    static vector<vector<int>> divisors;
    Solution() {
        if (divisors.empty()) divisors = getDivisor();
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        unordered_map<int, int> counter;
        for (int num:nums) counter[num]++;

        unordered_map<int, int> countD; // {x:y}, y is the count of numbers in nums that can be divided by x
        for (auto &[num, freq]:counter) {
            for (int divisor:divisors[num]) {
                countD[divisor] += freq;
            }
        }

        map<int, LL> pairCount; // count of pairs where gcd(i, j) == g
        int mx = *max_element(begin(nums), end(nums));
        for (int g=mx; g>=1; g--) {
            int c = countD[g];
            if (c <= 1) continue;
            pairCount[g] = (LL)c*(c-1)/2;
            for (int newG = 2*g; newG<=mx; newG+=g) {
                pairCount[g] -= pairCount[newG];
            }
        }

        vector<int> keys, vals, res;
        for (auto &[k, v]:pairCount) {
            keys.push_back(k);
            vals.push_back(v);
        }

        for (int i=1; i<vals.size(); i++) {
            vals[i] += vals[i-1];
        }

        for (int q:queries) {
            int index = lower_bound(begin(vals), end(vals), q+1) - begin(vals);
            res.push_back(keys[index]);
        }

        return res;
    }
};

vector<vector<int>> Solution::divisors;