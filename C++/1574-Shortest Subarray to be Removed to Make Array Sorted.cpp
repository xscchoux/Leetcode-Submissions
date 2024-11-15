// First AC, binary search
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size(), res = 0;
        vector<int> left(N+1, INT_MAX);
        left[0] = 0;

        for (int i=0; i<N; i++) {
            if (i == 0) {
                left[i+1] = arr[i];
                res++;
            } else {
                if (arr[i] >= arr[i-1]) {
                    left[i+1] = arr[i];
                    res++;
                } else {
                    break;
                }
            }
        }

        for (int i=N-1; i>=0; i--) {
            if (i == N-1 || arr[i] <= arr[i+1]) {
                int idx = upper_bound(left.begin(), left.begin()+i, arr[i]) - left.begin();
                idx--;
                res = max(res, N-i+idx);
            } else {
                break;
            }
        }

        return N-res;
    }
};



// Efficient two-pointer solution
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size(), res = N, left = 0, right = N-1;
        while (left+1<N && arr[left] <= arr[left+1]) left++;
        if (left == N-1) return 0;
        while (right > 0 && arr[right] >= arr[right-1]) right--;
        res = min(res, N-max(left+1, N-right));
        
        for (int i=0; i<=left; i++) {
            if (arr[i] <= arr[right]) {
                res = min(res, right-i-1);
            } else if (right < N-1){
                right++;
            } else {
                break;
            }
        }

        return res;
    }
};