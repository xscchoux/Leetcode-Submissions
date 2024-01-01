class Solution {
public:
    bool isOK(int number, vector<int>& nums){
        int N = nums.size();
        for (int i=0; i<number; i++){
            if (nums[i] == nums[N-number+i]) return false;
        }
        return true;
    }
    
    int minLengthAfterRemovals(vector<int>& nums) {
        // binary search
        int N = nums.size();
        int left = 0, right = N/2;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (isOK(mid, nums)) left = mid;
            else right = mid;
        }
        
        if (isOK(right, nums)){
            return N - 2*right;
        }
        return N - 2*left;
    }
};