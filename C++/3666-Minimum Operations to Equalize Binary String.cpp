// BFS, O(NlogN)
class Solution {
public:
    int minOperations(string s, int k) {
        int N = s.size();
        int zeroCnt = count(begin(s), end(s), '0');

        vector<set<int>> idx(2);
        vector<int> step(N+1, INT_MAX);
        step[zeroCnt] = 0;

        for (int i=0; i<=N; i++) {
            idx[i%2].insert(i);
        }

        queue<int> q;
        q.push(zeroCnt);
        idx[zeroCnt%2].erase(zeroCnt);

        while (!q.empty()) {
            int currCnt = q.front();
            q.pop();

            if (currCnt == 0) {
                return step[currCnt];
            }


            //    0 <= flippedZero <= min(currCnt, k)
            //    k - flippedZero <= N - currCnt
            // => max(k+currCnt-N, 0) <= flippedZero <= min(currCnt, k)           

            int flipZeroMin = max(k+currCnt-N, 0), flipZeroMax = min(currCnt, k);
            int zeroCntMin = currCnt + (k-flipZeroMax) - flipZeroMax, zeroCntMax = currCnt + (k-flipZeroMin) - flipZeroMin;
            auto& idxSet = idx[zeroCntMin%2];  // note that the parity of the difference betweeen the count of one and zero doesn't change 

            for (auto iter=idxSet.lower_bound(zeroCntMin); iter != idxSet.end() && *iter <= zeroCntMax;) {
                step[*iter] = step[currCnt]+1;
                q.push(*iter);
                iter = next(iter);
                idxSet.erase(prev(iter));
            }
        }

        return -1;
    }
};