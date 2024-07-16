// My solution
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        colors.insert(colors.end(), colors.begin(), colors.end()-(N-k+1)); // add k-1 elements
        vector<int> arr;
        for (int i=1; i<colors.size(); i++) {
            if (colors[i] != colors[i-1]) {
                arr.push_back(1);
            } else {
                arr.push_back(0);
            }
        }

        int curr = 0, res = 0;
        for (int i=0; i<arr.size(); i++) {
            curr += arr[i];
            if (i>=k-1) curr -= arr[i-k+1];
            if (curr == k-1) res++;
        }

        return res;
    }
};


// An efficient one
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        colors.insert(colors.end(), colors.begin(), colors.end()-(N-k+1)); // add k-1 elements
        int cnt = 1, res = 0;
        for (int i=1; i<colors.size(); i++) {
            if (colors[i] != colors[i-1]) cnt++;
            else cnt = 1;
            if (cnt >= k) res++;
        }

        return res;
    }
};