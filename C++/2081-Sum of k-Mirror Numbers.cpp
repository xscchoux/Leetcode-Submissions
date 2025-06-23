// first AC, O( 10*sqrt(10^10), the worst case is when k=7, the 30th number that satisfies the condition is 64454545446≈6×10^10 (but we don't know this at first) )
class Solution {
public:
    bool check(string numS, int k) {
        vector<int> arr;
        long long n = stoll(numS);
        while (n > 0) {
            arr.push_back(n%k);
            n = n/k;
        }
        int left = 0, right = arr.size()-1;
        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        // list all palindromes
        long long res = 0;
        int length = 1;
        
        while (true) {
            int half = length/2;
            if (length%2) {
                if (half != 0) {
                    for (int curr=pow(10, half-1); curr<pow(10, half); curr++) {
                        string halfString = "";
                        halfString += to_string(curr);
                        string reversed = halfString;
                        reverse(begin(reversed), end(reversed));
                        for (int middle = 0; middle <= 9; middle++) {
                            string num = halfString + to_string(middle) + reversed;
                            if (check(num, k)) {
                                res += stoll(num);
                                n--;
                                if (n == 0) {
                                    return res;
                                }
                            }
                        }
                    }
                } else {
                    for (int number=1; number<=9; number++) {
                        string num = to_string(number);
                        if (check(num, k)) {
                            res += stoll(num);
                            n--;
                            if (n == 0) {
                                return res;
                            }
                        }
                    }
                }
            } else {
                for (int curr=pow(10, half-1); curr<pow(10, half); curr++) {
                    string halfString = "";
                    halfString += to_string(curr);
                    string reversed = halfString;
                    reverse(begin(reversed), end(reversed));
                    string num = halfString + reversed;
                    if (check(num, k)) {
                        res += stoll(num);
                        n--;
                        if (n == 0) {
                            return res;
                        }
                    }
                }
            }
            length++;
        }
        return 0;
    }
};



// Much faster if we reuse the array
class Solution {
private:
    int digits[100];
public:
    bool check(string numS, int k) {
        long long n = stoll(numS);
        int idx = -1;
        while (n > 0) {
            ++idx;
            digits[idx] = n%k;
            n = n/k;
        }
        int left = 0, right = idx;
        while (left < right) {
            if (digits[left] != digits[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        // list all palindromes
        long long res = 0;
        int length = 1;
        
        while (true) {
            int half = length/2;
            if (length%2) {
                if (half != 0) {
                    for (int curr=pow(10, half-1); curr<pow(10, half); curr++) {
                        string halfString = "";
                        halfString += to_string(curr);
                        string reversed = halfString;
                        reverse(begin(reversed), end(reversed));
                        for (int middle = 0; middle <= 9; middle++) {
                            string num = halfString + to_string(middle) + reversed;
                            if (check(num, k)) {
                                res += stoll(num);
                                n--;
                                if (n == 0) {
                                    return res;
                                }
                            }
                        }
                    }
                } else {
                    for (int number=1; number<=9; number++) {
                        string num = to_string(number);
                        if (check(num, k)) {
                            res += stoll(num);
                            n--;
                            if (n == 0) {
                                return res;
                            }
                        }
                    }
                }
            } else {
                for (int curr=pow(10, half-1); curr<pow(10, half); curr++) {
                    string halfString = "";
                    halfString += to_string(curr);
                    string reversed = halfString;
                    reverse(begin(reversed), end(reversed));
                    string num = halfString + reversed;
                    if (check(num, k)) {
                        res += stoll(num);
                        n--;
                        if (n == 0) {
                            return res;
                        }
                    }
                }
            }
            length++;
        }
        return 0;
    }
};


// without using string
class Solution {
private:
    int digits[100];
public:
    bool check(long long n, int k) {
        int idx = -1;
        while (n > 0) {
            ++idx;
            digits[idx] = n%k;
            n = n/k;
        }
        int left = 0, right = idx;
        while (left < right) {
            if (digits[left] != digits[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        // list all palindromes
        long long res = 0;
        int length = 1;
        
        while (true) {
            int half = length/2;
            if (length%2) {
                for (int curr=pow(10, half); curr<pow(10, half+1); curr++) {
                    long long combined = curr, x = curr/10;
                    while (x) {
                        combined = combined*10 + x%10;
                        x /= 10;
                    }
                    if (check(combined, k)) {
                        res += combined;
                        n--;
                        if (n == 0) {
                            return res;
                        }
                    }
                }
            } else {
                for (int curr=pow(10, half-1); curr<pow(10, half); curr++) {
                    long long combined = curr, x = curr;
                    while (x) {
                        combined = combined*10 + x%10;
                        x /= 10;
                    }                    
                    if (check(combined, k)) {
                        res += combined;
                        n--;
                        if (n == 0) {
                            return res;
                        }
                    }
                }
            }
            length++;
        }
        return 0;
    }
};