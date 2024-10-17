// First AC
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        for (int i=0; i<s.size();i++) {
            int greaterIdx = -1;
            int curr = s[i];
            for (int j = i+1; j<s.size(); j++) {
                if (curr < s[j]) {
                    curr = s[j];
                    greaterIdx = j;
                } else if (curr == s[j] && curr != s[i]) {
                    greaterIdx = j;                    
                }
            }
            if (greaterIdx != -1) {
                swap(s[i], s[greaterIdx]);
                break;
            }
        }

        return stoi(s);
    }
};



// Truly O(n) solution
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int N = s.size(), swapIdx1 = -1, swapIdx2 = -1, largeIdx = -1;

        for (int i=N-1; i>=0; i--) {
            if (largeIdx == -1 || s[i] > s[largeIdx]) {
                largeIdx = i;
            } else if (s[i] < s[largeIdx]) {
                swapIdx1 = i;
                swapIdx2 = largeIdx;
            }
        }

        if (swapIdx1 != -1 && swapIdx2 != -1) {
            swap(s[swapIdx1], s[swapIdx2]);
        }

        return stoi(s);
    }
};