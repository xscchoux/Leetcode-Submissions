// First try, naive O(n^2) solution
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        unordered_set<int> used;
        int res = 0;
        for (int i=0; i<N; i++) {
            used.insert(arr[i]);
            bool chunk = true;
            for (int j=0; j<=i; j++) {
                if (!used.contains(j)) {
                    chunk = false;
                    break;
                }
            }
            if (chunk) res++;
        }

        return res;
    }
};




// clever O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        int mx = -1, res = 0;
        for (int i=0; i<N; i++) {
            mx = max(mx, arr[i]);
            if (i == mx) res++;
        }

        return res;
    }
};