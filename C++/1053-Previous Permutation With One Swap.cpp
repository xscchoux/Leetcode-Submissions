// binary search
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int N = arr.size();
        map<int, int> hmap;
        hmap[arr[N-1]] = N-1;

        for (int i=N-2; i>=0; i--) {
            auto it = hmap.lower_bound(arr[i]);
            if (it != hmap.begin()) {
                advance(it, -1);
                int ind = (*it).second;
                swap(arr[i], arr[ind]);
                return arr;
            }
            hmap[arr[i]] = i;
        }

        return arr;
    }
};


// two loops, harder
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int N = arr.size();
        if (N == 1) return arr;

        int idx = N-2;
        while (idx >= 0 && arr[idx] <= arr[idx+1]) {
            idx--;
        }

        if (idx == -1) return arr;
        
        int mxIdx = idx+1; // index of the maximum num smaller than arr[idx]

        for (int i=idx+1; i<N; i++) {
            if (arr[idx] > arr[i] && arr[mxIdx] < arr[i]) {
                mxIdx = i;
            }
        }
        swap(arr[idx], arr[mxIdx]);
        return arr;
    }
};