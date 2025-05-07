using LL = long long;
class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        vector<LL> prefixForward = {0}, prefixBackward = {0};
        int N = forward.size();
        
        for (int i=0; i<N; i++) {
            prefixForward.push_back(prefixForward.back() + forward[i]);
            prefixBackward.push_back(prefixBackward.back() + backward[i]);
        }
        
        LL res = 0;
        int pos = 0;
        for (int q:queries) {
            LL tmpForward = 0;
            if (q >= pos) {
                tmpForward = prefixForward[q] - prefixForward[pos];
            }
            else {
                tmpForward = (prefixForward.back() - prefixForward[pos]) + prefixForward[q];
            }

            LL tmpBackward = 0;
            if (pos >= q) {
                tmpBackward = prefixBackward[pos+1] - prefixBackward[q+1];
            }
            else {
                tmpBackward = (prefixBackward.back() - prefixBackward[q+1]) + prefixBackward[pos+1];
            }

            pos = q;
 
            res += min(tmpForward, tmpBackward);
        }

        return res;
    }
};