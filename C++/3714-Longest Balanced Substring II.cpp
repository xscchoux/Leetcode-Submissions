// https://leetcode.com/problems/longest-balanced-substring-ii/solutions/7268427/best-and-easiest-solution-hashing-prefix-sum-video-tutorial/
class Solution {
public:
    int count(char x, char y, string& s) {
        unordered_map<int, int> cnt;  // state of (x, y): index
        int tot = 0, maxCnt = 0;
        cnt[0] = -1;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == x) {
                tot++;
            } else if (s[i] == y) {
                tot--;
            } else {
                cnt.clear(); // O(N), but doesn't matter
                cnt[0] = i;
                tot = 0;
            }

            if (cnt.contains(tot)) {
                maxCnt = max(maxCnt, i-cnt[tot]);
            } else {
                cnt[tot] = i;
            }
        }

        return maxCnt;
    }
    int longestBalanced(string s) {
        int N = s.size(), res = 1;

        // case1: only one character
        int curr = 1;
        for (int i=1; i<N; i++) {
            if (s[i] == s[i-1]) {
                curr++;
            } else {
                res = max(res, curr);
                curr = 1;
            }
        }
        res = max(res, curr);

        // case2: only ab, ac, or bc
        res = max(count('a', 'b', s), res);
        res = max(count('a', 'c', s), res);
        res = max(count('b', 'c', s), res);

        // case3: has abc
        vector<int> counter(3, 0);
        map<pair<int, int>, int> hmap;
        hmap[{0, 0}] = -1;

        for (int i=0; i<N; i++) {
            counter[s[i]-'a']++;
            int diffAB = counter[0] - counter[1];
            int diffAC = counter[0] - counter[2];
            if (hmap.contains({diffAB, diffAC})) {
                res = max(res, i-hmap[{diffAB, diffAC}]);
            } else {
                hmap[{diffAB, diffAC}] = i;
            }
        }

        return res;
    }
};