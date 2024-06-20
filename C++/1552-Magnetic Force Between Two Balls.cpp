class Solution {
public:
    bool isOK(vector<int>& position, int dist, int m) {
        int prev = position[0];
        int cnt = 1;
        for (int i=1; i<position.size(); i++) {
            if ((position[i] - prev) >= dist) {
                cnt++;
                prev = position[i];
            } 
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0, right = position.back();
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(position, mid, m)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(position, right, m)) {
            return right;
        }
        return left;
    }
};