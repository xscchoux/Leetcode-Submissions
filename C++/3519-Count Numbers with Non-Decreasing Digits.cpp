using LL = long long;
class Solution {
public:
    LL dp[400][10][2];  // dp[idx][previous digit][reach limit? 1 if yes else 0]
    static constexpr int kMod = 1e9+7;
    int count(string& s, int idx, int prev, int limit, int base) {
        if (idx == s.size()) return 1;
        if (dp[idx][prev][limit] != -1) return dp[idx][prev][limit];

        int high = limit?(s[idx]-'0'):(base-1);
        LL res = 0;

        for (int curr = prev; curr <= high; curr++) {
            int newLimit = (limit && curr == high);
            res = (res + count(s, idx+1, curr, newLimit, base))%kMod;
        }

        return dp[idx][prev][limit] = res;
    }
    string convertS(string& s, int base) {  // convert a diigt string to another in base `b`
        string curr = s, res = "";
        while (curr != "0") {
            string q;
            int rem = 0;
            for (char c:curr) {
                int val = c-'0';
                q += ((val + 10*rem)/base + '0');
                rem = (val + 10*rem)%base;
            }
            res += rem + '0';
            int idx = 0;
            while (q[idx] == '0') {
                idx++;
            }
            if (idx < q.size()) curr = q.substr(idx);
            else curr = "0";
        }
        reverse(begin(res), end(res));
        return res;
    }
    int countNumbers(string l, string r, int b) {
        // Need l - 1;
        int endIdx = l.size()-1;
        while (l[endIdx] == '0') {
            l[endIdx] = '9';
            endIdx--;
        }
        l[endIdx] = ((l[endIdx] - '0')-1) + '0';
        int idx = 0;
        while (l[idx] == '0') {
            idx++;
        }
        l = l.substr(idx);
        if (l.empty()) l = "0";
        string newL = convertS(l, b), newR = convertS(r, b);
        memset(dp, -1, sizeof(dp));
        LL upper = count(newR, 0, 0, 1, b);
        memset(dp, -1, sizeof(dp));
        LL lower = count(newL, 0, 0, 1, b);
        return (upper-lower+kMod)%kMod;
    }
};