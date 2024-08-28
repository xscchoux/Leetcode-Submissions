// kind of brute-force. Convert all the numbers to arrays having maxmimum digits (7), and try forming all possiblites 
class Solution {
public:
    int makeInt(int tmp[7]) {
        int num = 0;
        for (int i=6; i>=0; i--) {
            num = num*10 + tmp[i];
        }

        return num;
    }
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        int tmp[7];
        memset(tmp, 0, sizeof(tmp));

        for (int num:nums) {
            res += cnt[num];
            unordered_set<int> s;
            s.insert(num);

            int ind = 0;
            while (num > 0) {
                tmp[ind++] = num%10;
                num /= 10;
            }
            while (ind < 7) tmp[ind++] = 0;

            for (int i=0; i<7; i++) {
                for (int j=i+1; j<7; j++) {
                    swap(tmp[i], tmp[j]);
                    s.insert(makeInt(tmp));

                    for (int k=0; k<7; k++) {
                        for (int l=k+1; l<7; l++) {
                            swap(tmp[k], tmp[l]);
                            s.insert(makeInt(tmp));
                            swap(tmp[k], tmp[l]);
                        }
                    }

                    swap(tmp[i], tmp[j]);
                }
            }

            for (int changed:s) {
                cnt[changed]++;
            }
        }

        return res;
    }
};




// sorting, smarter
class Solution {
public:
    int makeInt(int tmp[], int size) {  // int makeInt(int *tmp, int size) also works
        int num = 0;
        for (int i=size-1; i>=0; i--) {
            num = num*10 + tmp[i];
        }
        return num;
    }
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        sort(nums.rbegin(), nums.rend());


        for (int num:nums) {
            res += cnt[num];
            unordered_set<int> s;
            s.insert(num);

            int ind = 0, N = log10(num)+1;
            int tmp[N];
            while (num > 0) {
                tmp[ind++] = num%10;
                num /= 10;
            }

            for (int i=0; i<N; i++) {
                for (int j=i+1; j<N; j++) {
                    swap(tmp[i], tmp[j]);
                    s.insert(makeInt(tmp, N));

                    for (int k=0; k<N; k++) {
                        for (int l=k+1; l<N; l++) {
                            swap(tmp[k], tmp[l]);
                            s.insert(makeInt(tmp, N));
                            swap(tmp[k], tmp[l]);
                        }
                    }

                    swap(tmp[i], tmp[j]);
                }
            }

            for (int changed:s) {
                cnt[changed]++;
            }
        }

        return res;
    }
};