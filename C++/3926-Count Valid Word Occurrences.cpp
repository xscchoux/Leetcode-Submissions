class Solution {
public:
    void check(string& curr, unordered_map<string, int>& cnt) {
        string s;
        int N = curr.size();
        for (int i=0; i<N; i++) {
            if (curr[i] == '-') {
                if (i > 0 && curr[i-1] != '-' && i<N-1 && curr[i+1] != '-') {
                    s.push_back(curr[i]);
                } else {
                    if (!s.empty()) {
                        cnt[s]++;
                    }
                    s = "";
                }
            } else {
                s.push_back(curr[i]);
            }
        }
        if (!s.empty()) {
            cnt[s]++;
        }
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string, int> cnt;
        string curr = "";

        for (auto &c:chunks) {
            for (int i=0; i<c.size(); i++) {
                if (c[i] != ' ') {
                    curr.push_back(c[i]);
                } else {
                    check(curr, cnt);
                    curr = "";
                }
            }
        }
        if (!curr.empty()) {
            check(curr, cnt);
        }

        vector<int> res;
        for (auto &q:queries) {
            res.push_back(cnt[q]);
        }

        return res;
    }
};



// better
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s, curr;
        unordered_map<string, int> cnt;
        for (auto &c:chunks) {
            s += c;
        }

        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            if (ch>='a' && ch<='z') curr += ch;
            else if (s[i] == '-' && !curr.empty() && curr.back() != '-') curr += '-';
            else {
                while (!curr.empty() && curr.back() == '-') {
                    curr.pop_back();
                }
                if (!curr.empty()) {
                    cnt[curr]++;
                }
                curr = "";
            }
        }

        while (!curr.empty() && curr.back() == '-') {
            curr.pop_back();
        }
        if (!curr.empty()) {
            cnt[curr]++;
        }

        vector<int> res;
        for (auto &q:queries) {
            res.push_back(cnt[q]);
        }

        return res;

    }
};