class Solution {
public:
    long long minCost(int n) {
        // (a + b) = x
        // (a + b)^2 = x^2
        // ab = (x^2 - a^2 - b^2)/2
        // total = (x^2 - a^2 - b^2)/2 + (a^2 - a_split1^2 - a_split2^2) + (b^2 - b_split1^2 - b_split2^2) + ....
        // a and b (all intermediate squared values) cancel out, only x 1s left
        // tot = (x^2-x)/2
        return (long long)n*(n-1)/2;        
    }
};