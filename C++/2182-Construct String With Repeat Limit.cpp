class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char> pq;
        unordered_map<char, int> cnt;
        for (char c:s) cnt[c]++;
        for (auto &[k, v]:cnt) {
            pq.push(k);
        }

        string res;

        while (!pq.empty()) {
            char curr = pq.top();
            pq.pop();
            int count = min(repeatLimit, cnt[curr]);
            cnt[curr] -= count;
            res += string(count, curr);
            if (cnt[curr] > 0 && !pq.empty()) {
                char nxt = pq.top();
                cnt[nxt] -= 1;    // just put one element for the next
                res += nxt;
                if (cnt[nxt] == 0) {
                    pq.pop();
                }
                pq.push(curr);
            }
        }

        return res;
    }
};