// three pass
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums.size() <= 3) return false;

        int p, N = nums.size();
        for (p=0; p<nums.size()-1; p++) {
            if (nums[p] >= nums[p+1]) {
                break;
            }
        }

        if (p == 0 || p == N-1) return false;

        int q;
        for (q = p+1; q<nums.size(); q++) {
            if (nums[q] >= nums[q-1]) {
                break;
            }
        }

        if (q == N) return false;

        int curr;
        for (curr = q; curr < nums.size(); curr++) {
            if (nums[curr] <= nums[curr-1]) {
                return false;
            }
        }

        return true;
    }
};



// count turning points
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int switches = 0, N = nums.size();

        if (!(nums[1] > nums[0])) return false;

        for (int i=2; i<N; i++) {
            if (nums[i-1] == nums[i]) return false;
            if ((nums[i-2]-nums[i-1])*(nums[i-1]-nums[i]) < 0) {
                switches++;
            }
        }

        return switches == 2;
    }
};