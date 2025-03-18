// First AC, Lengthy and inefficient
using PII = pair<int, int>;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_set<int> picked;
        unordered_map<int, vector<int>> hmap;
        int N = nums1.size();
        vector<PII> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({nums1[i], i});
            hmap[nums1[i]].push_back(i);
        }

        sort(begin(arr), end(arr), [&](const PII a, const PII b) {
            return a.first > b.first || (a.first == b.first && nums2[a.second] > nums2[b.second]);
        });
        priority_queue<PII> pq;

        for (int i=1; i<N; i++) {
            int idx = arr[i].second;
            pq.push({nums2[idx], idx});
        }

        vector<long long> res(N);
        unordered_set<int> passedIdx;
        long long val = 0;
        for (int i=0; i<arr.size(); i++) {
            int idx = arr[i].second;
            passedIdx.insert(idx);
            if (picked.contains(idx)) {
                picked.erase(idx);
                val -= nums2[idx];
            }

            while (!hmap[arr[i].first].empty()) {
                int removeIdx = hmap[arr[i].first].back();
                hmap[arr[i].first].pop_back();
                if (picked.contains(removeIdx)) {
                    picked.erase(removeIdx);
                    val -= nums2[removeIdx];
                }
            }

            while (picked.size() < k && !pq.empty()) {
                auto [v, nxtIdx] = pq.top();
                pq.pop();
                if (!passedIdx.contains(nxtIdx) && arr[i].first > nums1[nxtIdx]) {
                    val += v;
                    picked.insert(nxtIdx);
                }
            }
            res[idx] = val;
        }

        return res;
    }
};


// Much better, use two "sum variables"
using LL = long long;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = nums1.size();
        vector<array<int, 3>> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({nums1[i], nums2[i], i});
        }
        
        priority_queue<int, vector<int>, greater<>> pq;  // candidate values
        sort(begin(arr), end(arr));

        // prevSum: k-sum from previous index where nums[arr[currIndex][2]] != nums[arr[previousIndex][2]]
        // currSum: k-sum from currIndex-1

        LL prevSum = 0, currSum = 0;  
        vector<LL> res(N);

        for (int i=0; i<N; i++) {
            if (i > 0 && arr[i][0] == arr[i-1][0]) {
                res[arr[i][2]] = prevSum;
            } else {
                res[arr[i][2]] = currSum;
                prevSum = currSum;
            }

            pq.push(arr[i][1]);
            currSum += arr[i][1];
            while (pq.size() > k) {
                currSum -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};