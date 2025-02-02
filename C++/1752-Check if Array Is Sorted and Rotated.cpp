// std::rotate(begin, middle, end):

// Moves elements from [middle, end) to the front.
// Moves elements from [begin, middle) to the back.

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        int N = nums.size();

        for (int i=0; i<N; i++) {
            rotate(begin(nums), begin(nums)+1, end(nums));
            int same = true;
            for (int i=0; i<N; i++) {
                if (nums[i] != numsCopy[i]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
        }

        return false;
    }
};



// clever O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int N = nums.size(), count = 0;
        for (int i=1; i<N; i++) {
            if (nums[i] < nums[i-1]) count++;
            if (count == 2) return false;
        }

        if (nums[N-1] > nums[0]) count++;
        if (count == 2) return false;

        return true;
    }
};