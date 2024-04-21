class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int one = 0, zero = 0;
        bool hasZero = false;
        int N = binary.size();
        int kMod = 1e9+7;
        
        // one: number of good subsequences ended with '1'
        // zero: number of good subsequences ended with '0'
        
        for (int i=0; i<N; i++) {
            if (binary[i] == '1') {
                one = (one+zero+1)%kMod;
            } else {
                hasZero = true;
                zero = (one + zero)%kMod;
            }
        }
        
        return (zero + one + (binary.find('0') == -1?0:1))%kMod;
    }
};