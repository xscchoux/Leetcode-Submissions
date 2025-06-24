// First AC, lengthy and slow
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int even = 0, odd = 0, N = nums.size();
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2) odd++;
            else even++;
        }

        if (abs(even-odd) != N%2) return -1;

        int res = INT_MAX;
        if (N%2) {
            deque<int> case1, case2;   // even at odd index, odd at even index 
            if (even > odd) {  // even num at even index
                int tmp = 0;
                for (int i=0; i<nums.size(); i++) {
                    if (nums[i]%2 == 0 && i%2) {
                        if (case2.empty()) {
                            case1.push_back(i);
                        } else {
                            int preIdx = case2.front();
                            case2.pop_front();
                            tmp += i - preIdx;
                        }
                    } else if (nums[i]%2 && i%2 == 0){
                        if (case1.empty()) {
                            case2.push_back(i);
                        } else {
                            int preIdx = case1.front();
                            case1.pop_front();
                            tmp += i - preIdx;
                        }
                    } 
                }
                res = min(res, tmp);
            } else {  // case1: odd num at odd index, case2: even num at even index
                int tmp = 0;
                for (int i=0; i<nums.size(); i++) {
                    if (nums[i]%2 && i%2) {
                        if (case2.empty()) {
                            case1.push_back(i);
                        } else {
                            int preIdx = case2.front();
                            case2.pop_front();
                            tmp += i - preIdx;
                        }
                    } else if (nums[i]%2 == 0 && i%2 == 0){
                        if (case1.empty()) {
                            case2.push_back(i);
                        } else {
                            int preIdx = case1.front();
                            case1.pop_front();
                            tmp += i - preIdx;
                        }
                    } 
                }
                res = min(res, tmp);
            }
        } else {
            // even first
            deque<int> case1, case2;  // case1:even at odd index, case2: odd at even index
            int tmp = 0;
            for (int i=0; i<nums.size(); i++) {
                if (nums[i]%2 == 0 && i%2) {
                    if (case2.empty()) {
                        case1.push_back(i);
                    } else {
                        int preIdx = case2.front();
                        case2.pop_front();
                        tmp += i - preIdx;
                    }
                } else if (nums[i]%2 && i%2 == 0){
                    if (case1.empty()) {
                        case2.push_back(i);
                    } else {
                        int preIdx = case1.front();
                        case1.pop_front();
                        tmp += i - preIdx;
                    }
                } 
            }
            res = min(res, tmp);

            // odd first
            case1.clear();
            case2.clear();  // case1:even at even index, case2: odd at odd index
            tmp = 0;
            for (int i=0; i<nums.size(); i++) {
                if (nums[i]%2 == 0 && i%2 == 0) {
                    if (case2.empty()) {
                        case1.push_back(i);
                    } else {
                        int preIdx = case2.front();
                        case2.pop_front();
                        tmp += i - preIdx;
                    }
                } else if (nums[i]%2 && i%2 == 1){
                    if (case1.empty()) {
                        case2.push_back(i);
                    } else {
                        int preIdx = case1.front();
                        case1.pop_front();
                        tmp += i - preIdx;
                    }
                } 
            }
            res = min(res, tmp);    
        }

        return res;
    }
};



// Much better
class Solution {
public:
    int countSwap(vector<int>& arr) {
        int swaps = 0;
        
        for (int i=0; i<arr.size(); i++) {
            swaps += abs(arr[i] - 2*i);   // when 0, 2, 4, ... are the indexes the elements in arr should be placed
        }

        return swaps;
    }
    int minSwaps(vector<int>& nums) {
        int N = nums.size();
        vector<int> evenArr, oddArr;

        for (int i=0; i<N; i++) {
            if (nums[i]%2) {
                oddArr.push_back(i);
            } else {
                evenArr.push_back(i);
            }
        }

        int Neven = evenArr.size(), Nodd = oddArr.size();
        if (abs(Neven - Nodd) > 1) return -1;

        int res = INT_MAX;

        if (Neven >= Nodd) {
            res = min(res, countSwap(evenArr));
        }

        if (Nodd >= Neven) {
            res = min(res, countSwap(oddArr));
        }

        return res;
    }
};