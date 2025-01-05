class Solution {
public:
    bool hasMatch(string s, string p) {
        int N = s.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<=N; j++) {
                string sub = s.substr(i, j-i);
                if (p.size()-1 > sub.size()) continue;
                int subStart = 0, subEnd = sub.size()-1;
                int start = 0, end = p.size()-1;
                while (start < p.size() && p[start] != '*') {
                    if (p[start] == sub[subStart]) start++, subStart++;
                    else break;
                }
                while (end >= 0 && p[end] != '*') {
                    if (p[end] == sub[subEnd]) end--, subEnd--;
                    else break;
                }
                if (p[start] == '*' && p[end] == '*') return true;
            }
        }

        return false;
    }
};


// clever solution using rfind()
class Solution {
public:
    bool hasMatch(string s, string p) {
        int starPos = p.find('*');
        string left = p.substr(0, starPos);
        string right = p.substr(starPos+1);
        int findLeft = s.find(left);
        int findRight = s.rfind(right);
        return findLeft != -1 && findRight != -1 && findLeft + left.size() <= findRight;

    }
};