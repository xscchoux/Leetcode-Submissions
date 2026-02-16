class Solution {
public:
    int reverseBits(int n) {
        int res = 0;

        for (int i=0; i<32; i++) {
            int val = n%2;
            n = n/2;

            res = res*2;
            res += val;
        }

        return res;
    }
};



class Solution {
public:
    int reverseBits(int n) {

        // For unsigned integers, shifted-out bits are discarded and zeros are shifted in.
        // For signed integers, left shifting into the sign bit is undefined behavior in C++.

        uint32_t tmp = n;

        tmp = (tmp << 16)|(tmp >> 16);
        tmp = ((tmp&0xff00ff00) >> 8)|((tmp&0x00ff00ff) << 8);
        tmp = ((tmp&0xf0f0f0f0) >> 4)|((tmp&0x0f0f0f0f) << 4);
        tmp = ((tmp&0xcccccccc) >> 2)|((tmp&0x33333333) << 2);
        tmp = ((tmp&0xaaaaaaaa) >> 1)|((tmp&0x55555555) << 1);        

        return tmp;
    }
};