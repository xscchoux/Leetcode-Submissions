class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int res = 0, N = skills.size();
        int pivot = 0;
        int cnt = 0;
        for (int i=1; i<N; i++) {
            if (skills[pivot] > skills[i]) {
                cnt++;
            } else {
                pivot = i;
                cnt = 1;
            }
            if (cnt == k) return pivot;
        }

        return pivot;
    }
};