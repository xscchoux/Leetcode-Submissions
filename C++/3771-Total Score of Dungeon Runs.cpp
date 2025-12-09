// https://leetcode.com/problems/total-score-of-dungeon-runs/solutions/7397331/easiest-sliding-window-priority-queue-ap-clwi/
using PLI = pair<long long, int>;
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int N = damage.size();
        vector<pair<long long, int>> arr;
        vector<bool> earned(N, false);

        long long currHP = hp;
        priority_queue<PLI, vector<PLI>, greater<>> pq;
        long long scoreGet = 0;
        
        for (int i=0; i<N; i++) {
            currHP -= damage[i];
            if (currHP < requirement[i]) {
                pq.push({requirement[i]-currHP, i});
            } else {
                earned[i] = true;
                scoreGet += 1;
            }
        }

        long long totScore = scoreGet, addedHP = 0;

        for (int i=1; i<N; i++) {
            if (earned[i-1]) {
                scoreGet--;
            }
            addedHP += damage[i-1];
            while (!pq.empty() && pq.top().first <= addedHP) {
                int idx = pq.top().second;
                pq.pop();

                if (i <= idx) {
                    scoreGet++;
                    earned[idx] = true;
                }
            }
            totScore += scoreGet;
        }


        return totScore;
    }
};