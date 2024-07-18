class Solution {
public:
    bool inString(string& curr, string& s, int k) {
        int N = s.size(), cnt = 0;
        int ind = 0;  // index of curr
        for (char c:s) {
            if (curr[ind] == c) ind++;
            if (ind == curr.size()) {
                cnt++;
                ind = 0;
            }
        }
        return cnt >= k;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnt(26), cand;
        for (char c:s) cnt[c-'a']++;
        for (int i=0; i<26; i++) {
             // since n < k * 8, there will be at most 7 items in cand
            if (cnt[i] >= k) cand.push_back(i);
        }

        queue<string> q;
        q.push("");
        string res = "";
        while (!q.empty()) {  // totally 7^1 + 7^2 +...+7^7 numbers for the queue
            int length = q.size();
            while (length-- > 0) {
                string prev = q.front();
                q.pop();
                for (int ind:cand) {             // O(7)
                    string curr = prev + char(97+ind);
                    if (inString(curr, s, k)) {  // O(s.size())
                        res = curr;
                        q.push(curr);
                    }
                }
            }
        }
        return res;
    }
};

// Looks like the time complexity : 7(7^7-1)/(7-1) * 7 * O(s.size()) is over 10e10, which exceeds 10e10, but pruning significantly reduces the total running time."