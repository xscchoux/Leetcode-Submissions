
// Backtracking, not sure how to analyze the time complexity, need update
// backtracking 1, prime factorization, slower, note the leftBubble and rightBubble trick
class Solution {
public:
    int bestDiff = INT_MAX, k, Nfac;
    vector<int> res;
    int bubbleRight(vector<int>& groups, int i) {
        // int newIdx = i;
        while (i+1 < k && groups[i] > groups[i+1]) {
            swap(groups[i], groups[i+1]);
            i++;
        }
        return i;
    }
    int bubbleLeft(vector<int>& groups, int i) {
        // int newIdx = i;
        while (i>0 && groups[i] < groups[i-1]) {
            swap(groups[i], groups[i-1]);
            i--;
        }
        return i;
    }

    void backtracking(int idx, vector<int>& groups, vector<int>& fac) {
        if (idx == Nfac) {
            int mx = *max_element(begin(groups), end(groups));
            int mn = *min_element(begin(groups), end(groups));
            if (mx - mn < bestDiff) {
                bestDiff = mx-mn;
                res = groups;
            }
            return;
        }
        for (int i=0; i<k; i++) {
            if (i > 0 && groups[i] == groups[i-1]) continue;

            groups[i] *= fac[idx];
            
            // keep groups sorted
            int newIdx = bubbleRight(groups, i);
            backtracking(idx+1, groups, fac);
            groups[newIdx] /= fac[idx];
            
            // keep groups sorted again
            bubbleLeft(groups, newIdx);
        }
    }

    vector<int> minDifference(int n, int k) {
        this->k = k;

        // prime factorization
        vector<int> fac;
        int tmp = n;
        for (int i=2; i*i<=n; i++) {
            while (tmp%i == 0) {
                tmp /= i;
                fac.push_back(i);
            }
        }
        if (tmp > 1) fac.push_back(tmp);

        this->Nfac = fac.size();
        if (Nfac < k) {
            while (fac.size() < k) {
                fac.push_back(1);
            }
            return fac;
        }

        // initialize k buckets
        vector<int> groups(k, 1);
        backtracking(0, groups, fac);

        return res;
    }
};


// simpler backtracking, faster
class Solution {
public:
    vector<int> res;
    int maxDiff = INT_MAX, k, n;
    void backtracking(int remain, int startNum, vector<int>& arr) {
        if (arr.size() == k) {
            if (remain == 1) {
                int mx = *max_element(begin(arr), end(arr));
                int mn = *min_element(begin(arr), end(arr));
                if (mx-mn < maxDiff) {
                    maxDiff = mx-mn;
                    res = arr;
                }
            }
            return;
        }

        for (int num=startNum; num<=remain; num++) {
            if (remain%num == 0) {
                arr.push_back(num);
                backtracking(remain/num, num, arr);
                arr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        this->k = k;
        this->n = n;
        vector<int> tmp;
        backtracking(n, 1, tmp);

        return res;
    }
};