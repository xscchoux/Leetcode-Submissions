// Check https://www.cnblogs.com/grandyang/p/14446497.html
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int N = stones.size();
        sort(stones.begin(), stones.end());

        // max(spaces between stones[0]~stones[N-2], spaces between stones[1]~stones[N-1])
        int mx = max(stones[N-2]-stones[0] + 1 - (N-1), stones[N-1]-stones[1] + 1 - (N-1));

        int left = 0, mn = N;
        for (int i=0; i<N; i++) {
            while (stones[i] - stones[left] + 1 > N) left++;
            int included = i-left+1;
            // when only one stone is not together with other N-1 stones
            if (included == N-1 && stones[i]-stones[left]+1 == N-1) { // edge case, so tough
                mn = min(mn, 2);
            } else {
                mn = min(mn, N-included);
            }
        }

        return {mn, mx};
    }
};