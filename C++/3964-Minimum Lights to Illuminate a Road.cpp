class Solution {
public:
    int minLights(vector<int>& lights) {
        vector<array<int, 2>> arr;
        int N = lights.size();
        // find interval
        for (int i=0; i<N; i++) {
            if (lights[i] > 0) {
                arr.push_back({max(0, i-lights[i]), min(i+lights[i], N-1)});
            }
        }
        // merge interval
        sort(begin(arr), end(arr));
        vector<array<int, 2>> newArr;
        newArr.push_back({-1, -1});
        for (int i=0; i<arr.size(); i++) {
            if (i > 0 && arr[i][0] <= newArr.back()[1] + 1) {
                newArr.back()[1] = max(arr[i][1], newArr.back()[1]);
            } else {
                newArr.push_back(arr[i]);
            }
        }

        // find unfilled
        vector<int> pos;
        for (int i=1; i<newArr.size(); i++) {
            if (i == 1) {
                pos.push_back(newArr[i][0] - 0);
            } else {
                pos.push_back(newArr[i][0] - newArr[i-1][1]-1);
            }
        }

        pos.push_back(N-1-newArr.back()[1]);

        int res = 0;
        for (int num:pos) {
            res += (num+2)/3;
        }

        return res;
    }
};