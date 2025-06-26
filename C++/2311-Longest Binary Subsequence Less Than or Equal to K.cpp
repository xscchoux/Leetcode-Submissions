// O(n^2*logn)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int N = s.size();
        map<int, long long, greater<>> hmap;  // length: minimum value
        hmap[0] = 0;
        int res = 0;

        for (int i=0; i<N; i++) {
            for (auto &[key, val]:hmap) {
                long long newVal = 2*val + (s[i]-'0');
                if (newVal > k) continue;
                res = max(res, key+1);
                if (!hmap.contains(key+1)) {
                    hmap[key+1] = newVal;
                } else {
                    hmap[key+1] = min(hmap[key+1], newVal);
                }
            }
        }

        return res;
    }
};


// O(n)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int N = s.size();
        int val = 0, cnt = 0;

        for (int i=N-1; i>=0; i--) {
            if (s[i] == '0') {
                cnt++;
            } else {
                if (N-i-1 <= 30 && val + (1<<(N-i-1)) <= k) {   // k ~ 10^9 ~ 2^30
                    val += (1<<(N-i-1));
                    cnt++;
                }
            }
        }

        return cnt;
    }
};