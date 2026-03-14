// brute-force, O(3*2^(n-1))
class Solution {
public:
    int count = 0;
    int n, k;
    string res;
    string original = "abc";
    void dfs(int idx, string &s) {
        if (idx == n) {
            count++;
            if (count == k) {
                res = s;
            }
            return;
        }
        if (count == k) return;

        for (char c:original) {
            if (s.empty() || s.back() != c && count < k) {
                s.push_back(c);
                dfs(idx+1, s);
                s.pop_back();
            }
        }

    }
    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string s = "";
        dfs(0, s);

        return res;
    }
};


// O(n)
class Solution {
public:
    string letters = "abc";
    string getHappyString(int n, int k) {
        string s = "";
        if (3 * pow(2, n-1) < k) {
            return "";
        } 
        for (int idx = 0; idx < n; idx++) {
            for (char c:letters) {
                if (!s.empty() && c == s.back()) continue;
                int cnt = pow(2, n-idx-1);
                if (k != 1 && k > cnt) {  // k != 1 is actually not needed here
                    k -= cnt;
                } else {
                    s += c;
                    break;
                }
            }
        }

        return s;
    }
};