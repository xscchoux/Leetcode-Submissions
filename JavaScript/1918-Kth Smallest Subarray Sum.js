/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var kthSmallestSubarraySum = function(nums, k) {
    let minimum = Number.POSITIVE_INFINITY, total = 0;
    for (let num of nums){
        minimum = Math.min(num, minimum);
        total += num;
    }
    
    let count = (mid) =>{
        let res = 0, tot = 0;
        let pointerL = 0;
        for (let pointerR=0; pointerR<nums.length; pointerR++){
            tot += nums[pointerR];
            while (tot > mid){
                tot-=nums[pointerL];
                pointerL++;
            }
            res += pointerR-pointerL+1;
        }
        return res;
    }
    
    let left = minimum, right = total;
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (count(mid) >= k){
            right = mid;
        }else{
            left = mid;
        }
    }
    if (count(left) >= k) return left;
    return right;
};