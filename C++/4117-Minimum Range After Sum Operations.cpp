class Solution {
public:
    int minRange(int a, int b, int c) {
        
        if (a+b<c) {
            return max(a, b);
        } else if (b+c<a) {
            return max(b, c);
        } else if (a+c<b) {
            return max(a, c);
        } else {
            return max({a, b, c}) - min({a, c, b});
        }

    }
};