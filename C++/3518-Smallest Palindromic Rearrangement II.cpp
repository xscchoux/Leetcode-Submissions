class Solution {
public:
    int combination(int m, int n, int limit) {
        int denominator = min(n, m-n);
        long long res = 1;

        for (int k=1; k<=denominator; k++) {
            res = res*(m-k+1)/k;
            if (res > limit) {
                return limit+1;
            }
        }

        return res;
    }
    int countPerm(int length, vector<int>& cnt, int k) {
        long long res = 1;
        for (int c=0; c<26; c++) {
            if (cnt[c] == 0) continue;
            int combinations = combination(length, cnt[c], k);
            if (combinations == k+1 || res*combinations > k) {
                return k;
            }
            res *= combination(length, cnt[c], k);
            length -= cnt[c];
        }

        return res;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);

        int sz = s.size();
        sz /= 2;

        for (char c:s) {
            cnt[c-'a']++;
        }

        string middle = "";
        for (int i=0; i<26; i++) {
            if (cnt[i]%2) middle.push_back(i+'a');
            cnt[i] /= 2;
        }

        string res = "";
        for (int i=0; i<sz; i++) {
            for (int c=0; c<26; c++) {
                if (cnt[c] == 0) continue;
                cnt[c]--;
                int permCount = countPerm(sz-i-1, cnt, k);
                if (permCount >= k) {
                    res.push_back(c+'a');
                    break;
                }
                cnt[c]++;
                k -= permCount;
            }
        }

        if (res.size() < sz) {
            return "";
        }


        string reversed = res;
        reverse(begin(reversed), end(reversed));

        return res + middle + reversed;
    }
};