vector<long long> arr;
int curr = 1, kMod = 1e9+7;
void init() {
    for (int i=1; i<=1000; i++) {
        long long tmp = 1;
        for (int k=1; k<=i; k++) {
            tmp = (tmp*curr)%kMod;
            curr++;
        }
        if (!arr.empty()) {
            arr.push_back((arr.back() + tmp)%kMod);
        } else {
            arr.push_back(tmp);
        }
    }
}


class Solution {
public:
    Solution () {
        if (arr.empty()) {
            init();
        }
    }
    int sumOfBlocks(int n) {
        return arr[n-1];
    }
};