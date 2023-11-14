class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int last1 = nums1[N-1], last2 = nums2[N-1];
        
        int swap1 = 0;
        // without swapping the last integer
        for (int i=0; i<N-1; i++){
            if (nums1[i] <= last1 && nums2[i] <= last2) continue;
            else if (nums1[i] <= last2 && nums2[i] <= last1) swap1++;
            else {
                return -1;
            }
        }

        int swap2 = 1;
        // without swapping the last integer
        for (int i=0; i<N-1; i++){
            if (nums1[i] <= last2 && nums2[i] <= last1) continue;
            else if (nums1[i] <= last1 && nums2[i] <= last2) swap2++;
        }
        
        return min(swap1, swap2);
    }
};