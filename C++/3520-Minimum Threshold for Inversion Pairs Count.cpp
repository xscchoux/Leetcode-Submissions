class FenwickTree {
private:
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) const {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int left, int right) const {
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
    int N;
    vector<int> sortedNums;

    int findIdx(int val) {  // find the first index in sortedNums where sortedNums[index] >= val
        int left = 0, right = N-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (sortedNums[mid] < val) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (sortedNums[left] >= val) return left;
        else if (sortedNums[right] >= val) return right;
        else return N;
    }

    bool isOK(vector<int>& nums, int x, int k) {
        FenwickTree FT(N);
        int count = 0;

        for (int num:nums) {
            int leftIdx = findIdx(num+1)+1, rightIdx = findIdx(num+x+1)+1;  // count 1s in the range: [leftIdx, rightIdx) in BIT
            if (rightIdx-1 >= leftIdx) count += FT.rangeQuery(leftIdx, rightIdx-1);
            if (count >= k) return true;
            
            FT.update(findIdx(num)+1, 1);
        }
        return false;
    }

    int minThreshold(vector<int>& nums, int k) {
        this->N = nums.size();
        sortedNums = nums;
        sort(begin(sortedNums), end(sortedNums));

        int left = 0, right = *max_element(begin(nums), end(nums));
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left, k)) return left;
        else if (isOK(nums, right, k)) return right;
        else return -1;
    }
};