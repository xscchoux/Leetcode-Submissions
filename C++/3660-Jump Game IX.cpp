// https://leetcode.com/problems/jump-game-ix/solutions/7115326/using-prefix-suffix-array-explained-in-depth-c-python-java/
// O(N)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixMax(N, 0), suffixMin(N, INT_MAX);

        prefixMax[0] = nums[0];
        for (int i=1; i<N; i++) {
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        suffixMin[N-1] = nums[N-1];
        for (int i=N-2; i>=0; i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        vector<int> res(N);
        res[N-1] = prefixMax.back();
        for (int i=N-2; i>=0; i--) {
            res[i] = prefixMax[i];
            // when max prefix value > smallest suffix value, we can jump to (larger left)->(smaller right)->(larger right)
            if (suffixMin[i+1] < prefixMax[i]) {  
                res[i] = res[i+1];
            }
        }

        return res;
    }
};



// monotonically increasing stack, very tricky and hard to come up with
class Solution {
public:
    struct Item {
        int maxVal;  // max value this connected component (nums[left]~nums[right]) can reach
        int left;
        int right;
    };
    vector<int> maxValue(vector<int>& nums) {
        int N = nums.size();
        vector<Item> stk;

        for (int i=0; i<N; i++) {
            Item curr = {nums[i], i, i};

            while (!stk.empty() && stk.back().maxVal > nums[i]) {
                Item tmp = stk.back();
                stk.pop_back();
                curr.left = tmp.left;
                curr.maxVal = max(curr.maxVal, tmp.maxVal);
            }

            stk.push_back(curr);
        }

        vector<int> res;
        for (int i=0; i<stk.size(); i++) {
            for (int idx = stk[i].left; idx<=stk[i].right; idx++) {
                res.push_back(stk[i].maxVal);
            }
        }
        
        return res;
    }
};