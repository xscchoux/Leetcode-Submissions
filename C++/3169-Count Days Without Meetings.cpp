// sweepline, use map
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> hmap;
        for (auto &m:meetings) {
            hmap[m[0]]++;
            hmap[m[1]+1]--;
        }

        int zeroPos = 1, res = 0, curr = 0;
        for (auto &[k, v]:hmap) {
            curr += v;
            if (zeroPos != -1) {
                res += k-zeroPos;
            }
            if (curr == 0) {
                zeroPos = k;
            } else {
                zeroPos = -1;
            }
        }

        res += days + 1 - hmap.rbegin()->first;

        return res;
    }
};



// much simpler, just sort
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int res = 0, prevEnd = 0;

        for (auto &m:meetings) {
            int u = m[0], v = m[1];
            if (u > prevEnd+1) {
                res += u-prevEnd-1;
            }
            prevEnd = max(prevEnd, v);
        }

        res += days-prevEnd;

        return res;
    }
};