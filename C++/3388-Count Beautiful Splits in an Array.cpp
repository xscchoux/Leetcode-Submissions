class Solution {
public:
    vector<int> z_array(vector<int>& s) {
        int N = s.size();
        vector<int> Z(N, 0);
        int l = 0, r = 0;
        for (int i=1; i<N; i++) {
            if (i>r) {
                l = r = i;
                while (r<N && s[r] == s[r-l]) {
                    r++;
                }
                Z[i] = r-l;
                r--;
            } else {
                int k = i-l;
                if (i + Z[k] <= r) {
                    Z[i] = Z[k];
                } else {
                    l = i;
                    while (r<N && s[r] == s[r-l]) {
                        r++;
                    }
                    Z[i] = r-l;
                    r--;                    
                }
            }
        }
        return Z;
    }

    int beautifulSplits(vector<int>& nums) {
        int N = nums.size();
        if (N<3) return 0;
        auto z1 = z_array(nums);
        int res = 0;

        for (int i=1; i<N-1; i++) {
            if (z1[i] >= i) {
                res += N-2*i;  // number of possible nums2
                vector<int> newNum(begin(nums)+i, end(nums));
                auto z2 = z_array(newNum);
                for (int j=1; j<i; j++) {
                    if (z2[j] >= j) {
                        res+=1;     // for the case: (0,0)(0)(0,2,2,0,1,2,1,2), after getting (0,0)(0,0)(2,2,0,1,2,1,2)
                    }
                }
            } else {
                vector<int> newNum(begin(nums)+i, end(nums));
                auto z2 = z_array(newNum);
                int N2 = nums.size()-i;

                for (int j=1; j<N2; j++) {
                    if (z2[j] >= j) {
                        res+=1;
                    }
                }
            }
        }

        return res;
    }
};


// alternative solution
class Solution {
public:
    vector<int> z_array(vector<int>& s) {
        int N = s.size();
        vector<int> Z(N, 0);
        int l = 0, r = 0;
        for (int i=1; i<N; i++) {
            if (i>r) {
                l = r = i;
                while (r<N && s[r] == s[r-l]) {
                    r++;
                }
                Z[i] = r-l;
                r--;
            } else {
                int k = i-l;
                if (i + Z[k] <= r) {
                    Z[i] = Z[k];
                } else {
                    l = i;
                    while (r<N && s[r] == s[r-l]) {
                        r++;
                    }
                    Z[i] = r-l;
                    r--;                    
                }
            }
        }
        return Z;
    }

    int beautifulSplits(vector<int>& nums) {
        int res = 0;
        int N = nums.size();
        if (N < 3) return 0;

        auto z1 = z_array(nums);
        // for (auto c:z1) cout << c;
        int nums2EndIdx;
        for (int i=1; i<N-1; i++) {
            if (z1[i] >= i) {
                res += N-2*i;
                nums2EndIdx = 2*i-1;
            } else {
                nums2EndIdx = N-1;
            }

            vector<int> newNum = vector<int>(nums.begin()+i, nums.end());
            auto z2 = z_array(newNum);        
            // for (auto c:z2) cout << c;
            for (int i2=i; i2<nums2EndIdx; i2++) {
                if (z2[i2+1-i] >= i2+1-i) {
                    res++;
                }
            }
        }

        return res;
    }

};