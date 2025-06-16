// First AC, slow
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        map<int, int> hmap;
        int N = nums.size();
        long long res = LLONG_MIN;
        for (int i=0; i<N; i++) {
            if (i + 1 >= m) {
                hmap[nums[i-m+1]]++;
            }
            if (nums[i] < 0 && !hmap.empty()) {  // if hmap is empty(), begin(hmap)->first is an undefined behavior
                res = max(res, (long long)nums[i]*(begin(hmap)->first));
            } else if (nums[i] >=0 && !hmap.empty()) {
                res = max(res, (long long)nums[i]*( (prev(end(hmap)))->first ));
            }
        }

        return res;
    }
};


// much better
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long mini = LLONG_MAX, maxi = LLONG_MIN;
        int N = nums.size();
        long long res = LLONG_MIN;

        for (int i=0; i<N; i++) {
            if (i + 1 >= m) {
                mini = min(mini, (long long)nums[i-m+1]);
                maxi = max(maxi, (long long)nums[i-m+1]);
                res = max(res, (long long)nums[i]*maxi);
                res = max(res, (long long)nums[i]*mini);
            }
        }

        return res;
    }
};