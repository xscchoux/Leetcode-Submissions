/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
// This doesn't work because the pattern can be very long !
//         long patternNum = 0;
//         for (int i=0; i<pattern.size(); i++) {
//             patternNum = patternNum*2 + pattern[i];
//         }
        
//         long long window = pow(2, pattern.size());
//         long num = 0;
//         long idx = 0;
        
//         while (true) {
//             int fetch = stream->next();
//             num = num*2;
//             if (idx >= pattern.size() - 1) num = num%window;
//             num += fetch;
//             if (idx >= pattern.size() - 1 && num == patternNum){
//                 return idx - pattern.size() + 1;
//             }
//             idx++;
//         }
        
//         return 0;

        bitset<100> streamSet, patternSet;
        int N = pattern.size();
        for (int i=0; i<N; i++) {
            streamSet[i] = (stream->next() == 1)?1:0;
            patternSet[i] = pattern[i];
        }
        int ind = 0;
        while (streamSet != patternSet) {
            streamSet >>= 1;
            streamSet[N-1] = (stream->next() == 1)?1:0;
            ind++;
        }
        return ind;
    }
};