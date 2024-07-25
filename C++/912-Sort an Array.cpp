// first attempt using C++, slow
class Solution {
public:
    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if (left > right) return {};
        if (left == right) return {nums[left]};

        int mid = left + (right-left)/2;
        vector<int> leftArr = mergeSort(nums, left, mid);
        vector<int> rightArr = mergeSort(nums, mid+1, right);
        int leftInd = 0, rightInd = 0;
        vector<int> newArr;

        while (leftInd < leftArr.size() && rightInd < rightArr.size()) {
            if (leftArr[leftInd] < rightArr[rightInd]) {
                newArr.push_back(leftArr[leftInd]);
                leftInd++;
            } else {
                newArr.push_back(rightArr[rightInd]);
                rightInd++;
            }
        }
        while (leftInd < leftArr.size()) {
            newArr.push_back(leftArr[leftInd]);
            leftInd++;            
        }
        while (rightInd < rightArr.size()) {
            newArr.push_back(rightArr[rightInd]);
            rightInd++;
        }
        return newArr;
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};


// Faster cause this saves space
class Solution {
public:
    int N;
    vector<int> temp;
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left > right) return;
        if (left == right) {
            temp[left] = nums[left];
            return;
        };

        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        int leftInd = left, rightInd = mid+1, curr = left;

        while (leftInd <= mid && rightInd <= right) {
            if (nums[leftInd] < nums[rightInd]) {
                temp[curr++] = nums[leftInd++];
            } else {
                temp[curr++] = nums[rightInd++];
            }
        }
        while (leftInd <= mid) {
            temp[curr++] = nums[leftInd++];           
        }
        while (rightInd <= right) {
            temp[curr++] = nums[rightInd++];
        }

        copy(temp.begin()+left, temp.begin()+right+1, nums.begin()+left);
    }
    vector<int> sortArray(vector<int>& nums) {
        this->N = nums.size();
        this->temp = vector<int>(N);
        mergeSort(nums, 0, nums.size()-1);

        return nums;
    }
};


// Using template
template <typename T>
class mergeSort {
    vector<T> arr;
public:
    void sort(vector<int>& nums) {
        this->arr = vector<T>(nums.size());
        split(nums, 0, nums.size()-1);
    }
private:
    void split(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right-left)/2;
        split(nums, left, mid);
        split(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        int l1 = left, l2 = mid+1, i = l1;
        while (l1 <= mid && l2 <= right) {
            arr[i++] = (nums[l1] <= nums[l2])?nums[l1++]:nums[l2++];
        }
        while (l1 <= mid) {
            arr[i++] = nums[l1++];
        }
        while (l2 <= right) {
            arr[i++] = nums[l2++];
        }
        copy(arr.begin()+left, arr.begin()+right+1, nums.begin()+left); // [left, right)
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort<int> n;
        n.sort(nums);
        return nums;
    }
};