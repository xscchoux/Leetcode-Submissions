// binary search
class Solution {
public:
    int bs(vector<int>& arr, int curr) {
        int left = 0, right = arr.size()-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] <= curr) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (arr[left] <= curr) {
            return left;
        } else if (arr[right] <= curr) {
            return right;
        } else {
            return -1;
        }

    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int res = 0;
        vector<int> arr;
        for (int j=0; j<N2; j++) {
            if (j < N1) {
                arr.push_back(nums1[j]);
                if (arr.size() > 1 && arr[j-1] < arr[j]) {
                    arr[j] = arr[j-1];
                }
            }
            int idx = bs(arr, nums2[j]);
            if (idx != -1) {
                res = max(res, j-idx);
            }   
        }

        return res;
    }
};




// O(n), two pointers
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // note that two arrays are non-decreasing
        int N1 = nums1.size(), N2 = nums2.size();
        int i = 0, res = 0;
        for (int j=0; j<N2; j++) {
            if (nums1[i] > nums2[j]) {
                i++;
                if (i >= N1) {
                    break;
                }
            }
            res = max(res, j-i);
        }

        return res;
    }
};