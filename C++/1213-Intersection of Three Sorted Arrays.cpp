class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i1 = 0, i2 = 0, i3 = 0, N1 = arr1.size(), N2 = arr2.size(), N3 = arr3.size();
        vector<int> res;
        while (i1<N1 && i2<N2 && i3<N3) {
            if (arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]) {
                res.push_back(arr1[i1]);
                i1++;i2++;i3++;
            } else {
                if (arr1[i1] <= min(arr2[i2], arr3[i3])) i1++;
                else if (arr2[i2] <= min(arr1[i1], arr3[i3])) i2++;
                else i3++;
            }
        }

        return res;
    }
};