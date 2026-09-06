class Solution {
public:
    long long k;
    long long getLength(long long x) {  // get the length of x numbers 
        long long d = 1, p = 1; // d: length of number, p: starting number of length d
        long long length = 0;

        while (10*p <= x) {
            length += 9*p*d;
            d++;
            p *= 10;
        }

        if (x-p+1 >= 0) length += (x-p+1)*d;

        return length;
    }
    bool isSmaller(long long x) {
        return getLength(x) < k;
    }
    int kthDigit(long long k) {
        this->k = k;

        long long left = 1, right = 1e15;
        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isSmaller(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // The smallest integer where the total length of the concatenated sequence from 1 to num is at least k
        long long num;
        
        if (!isSmaller(left)) {
            num = left;
        } else {
            num = right;
        }

        
        int pos = k - getLength(num-1);

        if ((num/10)&1) {  // in decreasing order
            num = (num/10)*10*2+9-num;
        }

        string s = to_string(num);
        return s[pos-1] - '0';
    }
};