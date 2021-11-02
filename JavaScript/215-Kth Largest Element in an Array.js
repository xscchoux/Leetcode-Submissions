/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    
    let partition = (left, right) =>{
        let pivotVal = nums[right], i = left;
        for (let j=left; j<=right; j++){
            if (nums[j] > pivotVal){
                [nums[j], nums[i]] = [nums[i], nums[j]];
                i++;
            }
        }
        [nums[right], nums[i]] = [nums[i], nums[right]];
        return i;
    }
    
    let search = (left, right) =>{
        if (left === right) return left;
        pivot = partition(left, right);
        if (pivot == k-1) return pivot;
        else if (pivot < k-1){
            return search(pivot+1, right);
        }else{
            return search(left, pivot-1);
        }
    }
    
    return nums[search(0, nums.length-1)];
};

