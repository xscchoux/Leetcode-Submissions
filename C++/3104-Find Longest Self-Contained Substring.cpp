class Solution {
public:
    int maxSubstringLength(string s) {
        int N = s.size();
        unordered_map<int, int> leftMost, rightMost;
        vector<vector<int>> preSum(N+1, vector<int>(26, 0));
        vector<int> totCnt(26, 0);

        for (int i=0; i<N; i++) {
            int charNum = s[i] - 'a';
            if (leftMost.find(charNum) == leftMost.end()) {
                leftMost[charNum] = i;
            }
            rightMost[charNum] = i;
            for (int j=0; j<26; j++) {
                preSum[i+1][j] = preSum[i][j] + (charNum==j?1:0);
            }
            totCnt[charNum]++;
        }

        int res = -1;
        for (auto &kv1:leftMost) {
            for (auto &kv2:rightMost) {
                int leftIdx = kv1.second, rightIdx = kv2.second;
                if (leftIdx > rightIdx || (leftIdx == 0 && rightIdx == N-1)) continue;
                bool isOK = true;
                for (int i=0; isOK && i<26; i++) {
                    if (preSum[rightIdx+1][i] - preSum[leftIdx][i] != totCnt[i] && preSum[rightIdx+1][i] - preSum[leftIdx][i] != 0) {
                        isOK = false;
                    }
                }
                if (isOK) {
                    res = max(res, rightIdx-leftIdx+1);
                }
            }
        }
        return res;
    }
};