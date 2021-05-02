/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    
    if (k <= 1){
        return 0;
    }
    
    let res = 0, left = 0, product = 1;
    
    for (let i=0; i<nums.length; i++){
        product *= nums[i];
        while (product >= k){
            product /= nums[left];
            left ++;
        }
        res += i - left + 1;
    }
    return res;
};