class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, int> cnt;

        for (auto &word:words) {
            int N = word.size();
            if (N <= 3) continue;
            for (int i=1; i<=N-2; i++) {
                string subWord = word.substr(0, i);
                subWord += to_string(N-i-1);
                subWord.push_back(word.back());
                cnt[subWord]++;
            }
        }

        vector<string> res;

        for (auto &word:words) {
            int N = word.size();
            if (N <= 3) {
                res.push_back(word);
                continue;
            }
            bool found = true;
            for (int i=1; i<=N-2; i++) {
                string sub = word.substr(0, i);
                string subWord = sub + to_string((N - (i+1))) + word.back();
                if (cnt[subWord] == 1 && (N - (i+1)) > 1) {
                    res.push_back(sub + to_string(N - (i+1) ) + word.back());
                    found = false;
                    break;
                }
            }
            if (found) {
                res.push_back(word);
            }
        }

        return res;
    }
};


// Much faster due to reduced map storage
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int N = words.size();
        queue<pair<int, int>> q;  // {prefix length, index}
        for (int i=0; i<N; i++) {
            q.push({1, i});
        }

        vector<string> res(N);

        while (!q.empty()) {
            unordered_map<string, vector<array<int, 2>>> cnt; // {abbreviation, count}
            // create abbreviations
            while (!q.empty()) {
                auto [preLen, idx] = q.front();
                q.pop();
                string s = words[idx];
                if (s.size() <= 3) {
                    cnt[s].push_back({0, idx});
                } else if (preLen + 1 == s.size() - 1) {
                    cnt[s].push_back({0, idx});
                } else {
                    string newS = s.substr(0, preLen) + to_string(s.size()-1-preLen) + s.back();
                    cnt[newS].push_back({preLen, idx});
                }
            }

            for (auto &[k, vec]:cnt) {
                if (vec.size() == 1) {
                    res[vec[0][1]] = k;
                } else {
                    for (auto [preLen, idx]:vec) {
                        q.push({preLen+1, idx});
                    }
                }
            }
        }

        return res;
    }
};