class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int N = nums.size();
        multiset<int> s;
        int left = 0;
        long long res = 0;

        for (int i=0; i<N; i++) {
            s.insert(nums[i]);
            while (*s.rbegin() - *s.begin() > 2) {
                s.erase(s.find(nums[left++]));
            }
            res += s.size();
        }

        return res;
    }
};



using PII = pair<int, int>;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int N = nums.size();
        priority_queue<PII, vector<PII>, greater<>> minHeap;
        priority_queue<PII> maxHeap;
        int left = 0;
        long long res=0;
        for (int i=0; i<N; i++) {
            minHeap.push({nums[i], i});
            maxHeap.push({nums[i], i});
            while (maxHeap.top().first - minHeap.top().first > 2) {
                left++;
                while (!maxHeap.empty() && maxHeap.top().second < left) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top().second < left) {
                    minHeap.pop();
                }
            }
            res += (i-left+1);
        }
        return res;
    }
};


// Use deque to create monotonically increasing/decreasing deque
using LL = long long;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        LL res = 0;
        int N = nums.size();
        deque<int> maxD, minD;
        int left = 0;
        for (int i=0; i<N; i++) {
            while (!maxD.empty() && nums[maxD.back()] <= nums[i]) maxD.pop_back();  // monotonically increasing
            while (!minD.empty() && nums[minD.back()] >= nums[i]) minD.pop_back();  // monotonically decreasing
            maxD.push_back(i);
            minD.push_back(i);

            while (nums[maxD.front()] - nums[minD.front()] > 2) {
                left++;
                while (maxD.front() < left) maxD.pop_front();
                while (minD.front() < left) minD.pop_front();
            }
            res += i-left+1;
        }

        return res;
    }
};