class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1; // edge case

        long long spf = value;  // smallest prime factor
        for (int i=2; i*i <= value; i++) {
            if (value%i == 0) {
                spf = i;
                break;
            }
        }

        // if value is even, we can have (value-2)/2 on the left side
        // if value is odd, we can have (value-spf)/2 on the left side  (value-spf, value-spf-2, value-spf-4, ....)        

        // check left side
        if (value%2 == 0) {
            int cnt = (value-2)/2;
            if (cnt < index) return -1;
        } else {
            int cnt = (value-spf)/2;
            if (cnt < index) return -1;
        }


        // if value is even, we can have value+2, value+4, .... on the right side
        // if value is odd, we can have value+spf, value+2, value+4, ... on the right side 

        // check right side
        if (index == n-1) return value;
        long long remain = n-index-1;
        if (value%2 == 0) {
            return value + 2*remain;
        } else {
            return value + spf + 2*(remain-1);
        }

    }
};