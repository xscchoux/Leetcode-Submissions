class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int minInd = 0, N = warehouse.size();
        int minVal = INT_MAX;
        
        for (int i=0; i<N; i++) {
            if (warehouse[i] < minVal) {
                minVal = warehouse[i];
                minInd = i;
            }
        }

        for (int i=1; i<=minInd; i++) {
            warehouse[i] = min(warehouse[i-1], warehouse[i]);
        }

        for (int i=N-2; i>=minInd; i--) {
            warehouse[i] = min(warehouse[i+1], warehouse[i]);
        }

        sort(warehouse.begin(), warehouse.end());
        sort(boxes.begin(), boxes.end());

        int j = 0;  // index of warehouses
        int res = 0;
        for (int i=0; i<boxes.size(); i++) {
            while (j < N && boxes[i] > warehouse[j]) {
                j++;
            }
            if (j == N) break;
            j++;
            res++;
        }

        return res;
    }
};