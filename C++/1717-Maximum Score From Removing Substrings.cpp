class Solution {
public:
    int getVal(string& s, string sub, int point) {
        vector<int> stk;
        int N = s.size();
        int p = 0;
        for (int i=0; i<N; i++) {
            if (!stk.empty() && s[i] == sub[1] && s[stk.back()] == sub[0]) {
                stk.pop_back();
                p += point;
            } else {
                stk.push_back(i);
            }
        }
        
        string newS;
        for (int i=0; i<stk.size(); i++) {
            newS += s[stk[i]];
        }
        s = newS;
        return p;
    }
    int maximumGain(string s, int x, int y) {
        string mx = "ab", mn = "ba";
        if (x < y) {
            mx = "ba"; mn = "ab";
            swap(x, y);
        }
        int res = 0;
        res += getVal(s, mx, x);
        res += getVal(s, mn, y);
        return res;
    }
};


// Better, two pointer
class Solution {
public:
    int getVal(string &s, string sub, int point) {
        int writeIndex = 0, N = s.size(), p = 0;
        for (int readIndex = 0; readIndex < N; readIndex++) {
            s[writeIndex++] = s[readIndex];

            if (writeIndex > 1 && s[writeIndex-1] == sub[1] && s[writeIndex-2] == sub[0]) {
                p += point;
                writeIndex -= 2;
            }
        }
        s.erase(s.begin() + writeIndex, s.end());

        return p;
    }
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x < y) {
            res += getVal(s, "ba", y);
            res += getVal(s, "ab", x);
        } else {
            res += getVal(s, "ab", x);
            res += getVal(s, "ba", y);            
        }
        return res;
    }
};