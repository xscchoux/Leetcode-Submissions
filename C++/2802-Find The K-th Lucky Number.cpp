class Solution {
public:
    string kthLuckyNumber(int k) {
        int n = 1;

        while (k > (1<<n)) {
            k -= (1<<n);
            n++;
        }

        k--;

        deque<char> ls;

        while (n > 0) {
            if (k%2 == 1) ls.push_front('7');
            else ls.push_front('4');
            k = k/2;
            n--;
        }

        return string(ls.begin(), ls.end());
    }
};