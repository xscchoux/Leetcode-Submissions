// O(nlogn)
using LL = long long;
class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int N = xCoord.size();
        vector<int> p(N);
        for (int i=0; i<N; i++) p[i] = i;

        sort(begin(p), end(p), [&](int i, int j) {
            return (xCoord[i] < xCoord[j] || (xCoord[i] == xCoord[j] && yCoord[i] < yCoord[j]));
        });

        map<pair<int, int>, int> seg;  // two points on a side: x coordinate

        int left=0;
        LL res = -1;
        for (int i=1; i<N; i++) {
            if (xCoord[p[i]] == xCoord[p[left]]) continue;

            // found rectangles from previous records in seg
            for (int k=left; k<i-1; k++) {
                auto currPair = make_pair(yCoord[p[k]], yCoord[p[k+1]]);
                auto it = seg.find(currPair);
                if (it != seg.end()) {
                    res = max(res, (LL)(xCoord[p[left]]-seg[currPair])*(it->first.second - it->first.first) );
                }
            }

            // remove old segments
            for (int k=left; k<i; k++) {
                int y = yCoord[p[k]];
                while (!seg.empty()) {
                    auto it = seg.upper_bound(make_pair(y, INT_MAX));
                    if (it == seg.begin() || prev(it)->first.second < y ) break;
                    it--;
                    seg.erase(it);
                }
            }

            // add new segments (new sides)
            for (int k=left; k<i-1; k++) {
                auto currPair = make_pair(yCoord[p[k]], yCoord[p[k+1]]);
                seg[currPair] = xCoord[p[left]];
            }

            left = i;
        }

        // check rectangles
        for (int k=left; k<N-1; k++) {
            auto currPair = make_pair(yCoord[p[k]], yCoord[p[k+1]]);
            auto it = seg.find(currPair);
            if (it != seg.end()) {
                res = max(res, (LL)(xCoord[p[left]]-seg[currPair])*(it->first.second - it->first.first) );
            }
        }

        return res;
    }
};