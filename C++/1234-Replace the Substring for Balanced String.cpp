// First AC, inefficient solution using binary search
class Solution {
public:
    bool isOK(int length, string &s, unordered_map<char, int> hmap, int count) {
        for (int i=0; i<length; i++) {
            hmap[s[i]]--;
        }
        if (hmap['Q']<=count && hmap['W']<=count && hmap['E']<=count && hmap['R']<=count) return true;
        
        for (int i=length; i<s.size(); i++) {
            hmap[s[i]]--;
            hmap[s[i-length]]++;
            if (hmap['Q']<=count && hmap['W']<=count && hmap['E']<=count && hmap['R']<=count) return true;
        }
        return false;
    }
    int balancedString(string s) {
        int count = s.size()/4;
        unordered_map<char, int> hmap;
        for (char c:s) hmap[c]++;

        int left = 0, right = s.size();
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(mid, s, hmap, count)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(left, s, hmap, count)) return left;
        return right;
    }
};

// clever solution using sliding window 
class Solution {
public:
    int balancedString(string s) {
        int N = s.size(), k = N/4;
        unordered_map<char, int> cnt;
        for (char c:s) {
            cnt[c]++;
        }

        int left = 0, res = N;
        for (int i=0; i<N; i++) {
            cnt[s[i]]--;
            while (left < N && cnt['Q'] <= k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k) {
                res = min(res, i-left+1);
                cnt[s[left]]++;
                left++;
            }
            
        }

        return res;
    }
};