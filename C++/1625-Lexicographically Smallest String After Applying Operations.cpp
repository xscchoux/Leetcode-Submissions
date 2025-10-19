// inefficient BFS, first AC
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int N = s.size();
        string res = s;
        deque<string> dq;
        dq.push_front(s);
        unordered_set<string> used;
        unordered_set<string> placed;
        placed.insert(s);

        while (!dq.empty()) {
            int length = dq.size();
            while (length-- > 0) {
                string curr = dq.front();
                if (used.find(curr) == used.end()) {
                    used.insert(curr);
                } else {
                    continue;
                }
                res = min(res, curr);
                used.insert(curr);
                dq.pop_front();

                for (int t=0; t<9; t++) {
                    for (int i=1; i<N; i+=2) {
                        curr[i] = ((curr[i]-'0') + a)%10 + '0';
                    }
                    if (placed.find(curr) == placed.end()) {
                        placed.insert(curr);
                        dq.push_back(curr);
                    }

                    string newCurr = curr.substr(b) + curr.substr(0, b);
                    if (placed.find(newCurr) == placed.end()) {
                        placed.insert(newCurr);
                        dq.push_back(newCurr);
                    }                        
                }
            }
        }

        return res;
    }
};


// O(n^2), clever solution
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int N = s.size();
        vector<int> bestNum(10, 0);

        for (int i=1; i<=9; i++) {
            bestNum[i] = i;
            for (int j=1; j<=9; j++) {
                bestNum[i] = min(bestNum[i], (i+j*a)%10);
            }
        }

        vector<bool> canRotate(N, false);
        canRotate[0] = true;
        for (int i=1; i<N; i++) {
            canRotate[(i*b)%N] = true;
        }

        string res = s;

        for (int i=0; i<N; i++) {
            if (!canRotate[i]) continue;

            string tmp = s;
            rotate(tmp.rbegin(), tmp.rbegin() + i, tmp.rend()); // right rotated by i

            if (b&1) {
                // we can also add `a` to all even indices of s when b is odd
                int evenMove = bestNum[tmp[0]-'0'] - (tmp[0]-'0');
                int oddMove = bestNum[tmp[1]-'0'] - (tmp[1]-'0');
                for (int j=0; j<N; j++) {
                    if (j&1) {
                        tmp[j] = (tmp[j]-'0' + oddMove + 10)%10 + '0';
                    } else {
                        tmp[j] = (tmp[j]-'0' + evenMove + 10)%10 + '0';
                    }
                }
            } else {
                int oddMove = bestNum[tmp[1]-'0'] - (tmp[1]-'0');
                for (int j=1; j<N; j+=2) {
                    tmp[j] = (tmp[j]-'0' + oddMove + 10)%10 + '0';
                }                
            }

            res = min(res, tmp);
        }

        return res;
    }
};