// Solution 1, stack + counting
class Solution {
public:
    string robotWithString(string s) {
        string res;
        vector<int> cnt(26, 0);
        for (char c:s) {
            cnt[c-'a']++;
        }

        stack<char> stk;
        int smallestIdx = 0;
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]-'a']--;
            while (smallestIdx < 26 && cnt[smallestIdx] == 0) {
                smallestIdx++;
            }
            stk.push(s[i]);
            while (smallestIdx < 26 && !stk.empty() && (stk.top() -'a') <= smallestIdx ) {
                res += stk.top();
                stk.pop();
            }
        }

        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};


// Solution 2, stack + vector that stores next smallest character
class Solution {
public:
    string robotWithString(string s) {
        int N = s.size();
        vector<char> nxtSmallest(N+1, 'z'+1);
        for (int i=N-1; i>=0; i--) {
            if (s[i] < nxtSmallest[i+1]) {
                nxtSmallest[i] = s[i];
            } else {
                nxtSmallest[i] = nxtSmallest[i+1];
            }
        }
        
        stack<char> stk;
        string res;

        for (int i=0; i<N; i++) {
            stk.push(s[i]);
            while (!stk.empty() && stk.top() <= nxtSmallest[i+1]) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};