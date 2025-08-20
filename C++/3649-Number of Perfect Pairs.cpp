class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // The second condition: max(|a - b|, |a + b|) >= max(|a|, |b|) is always true
        // For the fist condition: min(|a - b|, |a + b|) <= min(|a|, |b|)
        // Let x = |a|, y = |b|
        // case 1 (a and b have the same sign):
        //    |a + b| = x + y, |a - b| = |x - y|
        // case 2 (a and b have opposite sign):
        //    |a + b| = |x - y|, |a - b| = x + y
        // Therefore the multiset {∣a−b∣,∣a+b∣}={x+y,∣x−y∣}
        // When x >= y, 
        // min(|a-b|, |a+b|) = x-y
        // The first condition reduce to x-y <= y
        // x <= 2*y

        vector<int> arr;
        for (int num:nums) {
            arr.push_back(abs(num));
        }
        
        sort(begin(arr), end(arr));
        long long res = 0;
        int left = 0;
        for (int i=0; i<arr.size(); i++) {
            
            while (left < i && 2*arr[left] < arr[i]) {
                left++;
            }
            res += i-left;
        }

        return res;
    }
};