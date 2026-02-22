class Solution {
public:
    string rearrangeString(string s, int k) {
        int cnt[26] = {};

        for (char c:s) {
            cnt[c-'a']++;
        }

        priority_queue<pair<int, int>> ready;

        for (int i=0; i<26; i++) {
            if (cnt[i] == 0) continue;
            ready.push({cnt[i], i});
        }

        queue<pair<int, int>> stored;
        string res = "";

        for (int i=0; i<s.size(); i++) {
            if (!stored.empty() && i - stored.front().first >= k) {
                int c = stored.front().second;
                ready.push({cnt[c], c});
                stored.pop();
            }

            if (ready.empty()) return "";

            auto [currCnt, currChar] = ready.top();
            ready.pop();
            cnt[currChar]--;
            res += currChar + 'a';

            if (cnt[currChar] > 0) {
                stored.push({i, currChar});
            }
        }

        return res;
    }
};