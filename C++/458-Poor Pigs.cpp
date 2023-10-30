class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // states^pigs >= buckets
        // pigs >= log states_(buckets)
        // states**pigs >= buckets
        // use binary search to find pigs
        // pow() function returns a floating-point number (double)
        // - Smallest positive value: around 2.225 x 10^(-308)
        // - Largest positive value: around 1.798 x 10^(308)
        
        int states = minutesToTest/minutesToDie + 1;
        int left = 0, right = buckets;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (pow(states, mid) < buckets){
                left = mid;
            }else {
                right = mid;
            }
        }
        if (pow(states, left) >= buckets) return left;
        return right;
    }
};