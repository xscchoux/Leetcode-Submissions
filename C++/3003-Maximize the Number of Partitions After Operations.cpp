// O(n*k*26), note the clever way we analyze the time complexity
// https://leetcode.cn/problems/maximize-the-number-of-partitions-after-operations/solutions/2595072/ji-yi-hua-sou-suo-jian-ji-xie-fa-pythonj-6g5z/
using LL = long long;
class Solution {
public:
    int N, k;
    unordered_map<LL, int> memo;
    int dfs(int idx, LL mask, int canChange, string& s) {
        if (idx == N) return 0;
        LL key = ((LL)idx<<30)|(mask<<1)|canChange;
        if (memo.contains(key)) return memo[key];

        int c = s[idx]-'a', res = 0;
        
        // without change
        if (mask & (1<<c)) {
            res = max(res, dfs(idx+1, mask, canChange, s));
        } else {
            LL newMask = mask|(1<<c);
            if (__builtin_popcount(newMask) > k) {
                res = max(res, 1+dfs(idx+1, 1<<c, canChange, s));
            } else {
                res = max(res, dfs(idx+1, newMask, canChange, s));
            }
        }

        // with change
        if (canChange) {
            for (int i=0; i<26; i++) {
                if ((mask & (1<<i)) || i == c) continue;
                LL newMask = mask|(1<<i);
                if (__builtin_popcount(newMask) > k) {
                    res = max(res, 1+dfs(idx+1, 1<<i, 0, s));
                } else {
                    res = max(res, dfs(idx+1, newMask, 0, s));
                }                
            }
        }

        return memo[key] = res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        this->N = s.size();
        this->k = k;

        return 1+dfs(0, 0, 1, s);
    }
};


// O(N), prefix and suffix, very hard
// https://leetcode.cn/problems/maximize-the-number-of-partitions-after-operations/solutions/2595072/ji-yi-hua-sou-suo-jian-ji-xie-fa-pythonj-6g5z/
using u16 = unsigned short;
struct Data {
    int seg = 0;
    int cnt = 0;
    bitset<26> mask = {};
};
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int N = s.size();
        vector<Data> prev(N), suff(N);

        int seg = 0, cnt = 0;
        bitset<26> mask = {};
        for (int i=0; i<N-1; i++) {
            int num = s[i] - 'a';
            if (mask[num] == 0) {
                if (++cnt > k) {
                    seg++;
                    cnt = 1;
                    mask = {};
                }
                mask[num] = 1;
            }
            prev[i+1] = Data(seg, cnt, mask);
        }

        seg = 0;
        cnt = 0;
        mask = {};
        for (int i=N-1; i>0; i--) {
            int num = s[i] - 'a';
            if (mask[num] == 0) {
                if (++cnt > k) {
                    seg++;
                    cnt = 1;
                    mask = {};
                }
                mask[num] = 1;
            }
            suff[i-1] = Data(seg, cnt, mask);
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            auto [leftSeg, leftCnt, leftMask] = prev[i];
            auto [rightSeg, rightCnt, rightMask] = suff[i];
            bitset<26> totMask = (leftMask|rightMask);
            int totBit = totMask.count();
            if (min(totBit+1, 26) <= k) {
                res = max(res, leftSeg + rightSeg + 1);
            } else {
                if (leftCnt == k && rightCnt == k && totBit < 26) {
                    res = max(res, leftSeg + rightSeg + 3);
                } else {
                    res = max(res, leftSeg + rightSeg + 2);
                }
            }
        }

        return res;
    }
};


