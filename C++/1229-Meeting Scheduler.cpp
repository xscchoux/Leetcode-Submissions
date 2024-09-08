class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int i = 0, j = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        while (i < slots1.size() && j < slots2.size()) {
            int left = max(slots1[i][0], slots2[j][0]);
            int right = min(slots1[i][1], slots2[j][1]);
            if (right-left >= duration) {
                return {left, left+duration};
            }
            if (slots1[i][1] <= slots2[j][1]) i++;
            else j++;
        }

        return {};
    }
};