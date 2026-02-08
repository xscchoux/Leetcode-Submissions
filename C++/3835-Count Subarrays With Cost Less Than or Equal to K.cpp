// multiset
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<int> ms;
        int N = nums.size(), left = 0;
        long long res = 0;
        
        for (int i=0; i<N; i++) {
            ms.insert(nums[i]);
            while (ms.size() > 1 && (*rbegin(ms) - *begin(ms))*ms.size() > k) {
                ms.erase(ms.find(nums[left]));
                left++;
            }
            res += ms.size();
        }
        
        return res;
    }
};



// Two deques
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> mx, mn;
        int N = nums.size(), left = 0;
        long long res = 0;

        for (int i=0; i<N; i++) {
            while (!mx.empty() && nums[mx.back()] <= nums[i]) {
                mx.pop_back();
            }
            while (!mn.empty() && nums[mn.back()] >= nums[i]) {
                mn.pop_back();
            }

            mx.push_back(i);
            mn.push_back(i);

            while (left < i && (long long)(nums[mx.front()] - nums[mn.front()])*(i-left+1) > k) {
                if (mx.front() == left) {
                    mx.pop_front();
                }
                if (mn.front() == left) {
                    mn.pop_front();
                }
                left++;
            }
            res += i-left+1;
        }

        return res;
    }
};