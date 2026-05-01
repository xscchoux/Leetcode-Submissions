using LL = long long;
class Solution {
public:
    int side;
    bool isOK(int dist, vector<LL>& pos, int k) {
        for (int start:pos) {
            long long endPos = min(4LL*side-1, 4LL*side + start - dist);
            long long curr = start;
            for (int step=1; step<=k-1; step++) {
                auto it = lower_bound(begin(pos), end(pos), (LL)curr + dist);
                if (it == pos.end() || *it > endPos) {
                    curr = -1;
                    break;
                }
                curr = *it;
            }
            if (curr > 0) {
                return true;
            } 
        }

        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {

        vector<LL> pos; // Think of the coordinates on a straight line in clockwise order
        this->side = side;
        for (auto &p:points) {
            int c = p[1], r = p[0];
            if (c == 0) {
                pos.push_back(r);
            } else if (r == side) {
                pos.push_back(side+c);
            } else if (c == side) {
                pos.push_back(3LL*side-r);
            } else {
                pos.push_back(4LL*side - c);
            }
        }
        
        sort(begin(pos), end(pos));

        // Note that k >= 4, the max Manhattan distance is side
        int left = 1, right = side;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(mid, pos, k)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(right, pos, k)) {
            return right;
        }

        return left;
    }
};