class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int N = conflictingPairs.size();

        // swap if needed
        for (auto &p:conflictingPairs) {
            if (p[0] > p[1]) swap(p[0], p[1]);
        }

        // no need to sort
        // sort(begin(conflictingPairs), end(conflictingPairs), [](const auto& a, const auto &b) {
        //     return a[1] == b[1]?a[0]<b[0]:a[1]<b[1];
        // });

        vector<vector<int>> num2pairIdx(n+1);
        for (int pairIdx=0; pairIdx < conflictingPairs.size(); pairIdx++) {
            num2pairIdx[conflictingPairs[pairIdx][0]].push_back(pairIdx);
            num2pairIdx[conflictingPairs[pairIdx][1]].push_back(pairIdx);
        }

        // number of subarrays without any conflicting pairs
        int left = 1, currPair = 0;
        vector<int> cnt(conflictingPairs.size()+1, 0);
        long long res = 0;
        for (int i=1; i<=n; i++) {
            for (int pairIdx:num2pairIdx[i]) {
                cnt[pairIdx]++;
                if (cnt[pairIdx] == 2) currPair++;
            }
            while (currPair >= 1) {
                for (int pairIdx:num2pairIdx[left]) {
                    cnt[pairIdx]--;
                    if (cnt[pairIdx] == 1) currPair--;
                }
                left++;
            }
            res += i-left+1;
        }

        // removes[k] stores the number of subarrays that "only" contains the kth conflicting pair 
        int id = 0;
        left = 1;
        currPair = 0;
        cnt.assign(N+1, 0);
        vector<long long> removes(N+1, 0);

        for (int i=1; i<=n; i++) {
            for (int pairIdx:num2pairIdx[i]) {
                cnt[pairIdx]++;
                if (cnt[pairIdx] == 2) {
                    id ^= pairIdx;
                    currPair++;
                }
            }
            while (currPair > 1) {
                for (int pairIdx:num2pairIdx[left]) {
                    cnt[pairIdx]--;
                    if (cnt[pairIdx] == 1) {
                        currPair--;
                        id ^= pairIdx;
                    }
                }
                left++;
            }
            if (currPair == 1) {
                removes[id] += conflictingPairs[id][0] - left + 1;
            }
            
        }

        return res + *max_element(begin(removes), end(removes));
    }
};



// revisit, another solution
// https://leetcode.cn/problems/maximize-subarrays-after-removing-one-conflicting-pair/solutions/3603047/mei-ju-zuo-duan-dian-wei-hu-zui-xiao-ci-4nvu6/
// O(nlogn)
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> groups(n+1); // group[a] = {b1, b2,...}, a is start point and b1, b2 are end points
        for (auto &p:conflictingPairs) {
            if (p[0] > p[1]) {
                swap(p[0], p[1]);
            }
            int a = p[0], b = p[1];
            groups[a].push_back(b);
        }

        vector<int> endPoints = {n+1, n+1};
        vector<long long> extraLength(n+2, 0);
        long long res = 0;

        for (int start=n; start>=1; start--) {
            endPoints.insert(end(endPoints), begin(groups[start]), end(groups[start]));
            sort(begin(endPoints), end(endPoints));
            endPoints.resize(2);

            res += endPoints[0] - start;
            extraLength[endPoints[0]] += endPoints[1] - endPoints[0];
        }

        return res + *max_element(begin(extraLength), end(extraLength));
    }
};


// O(n), without sorting
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> groups(n+1); // group[a] = {b1, b2,...}, a is start point and b1, b2 are end points
        for (auto &p:conflictingPairs) {
            if (p[0] > p[1]) {
                swap(p[0], p[1]);
            }
            int a = p[0], b = p[1];
            groups[a].push_back(b);
        }

        int endPoint1 = n+1, endPoint2 = n+1;
        vector<long long> extraLength(n+2, 0);
        long long res = 0;

        for (int start=n; start>=1; start--) {
            for (int end:groups[start]) {
                if (end < endPoint1) {
                    endPoint2 = endPoint1;
                    endPoint1 = end;
                } else if (end < endPoint2) {
                    endPoint2 = end;
                }
            }

            res += endPoint1 - start;
            extraLength[endPoint1] += endPoint2 - endPoint1;
        }

        return res + *max_element(begin(extraLength), end(extraLength));
    }
};
