/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k = k%nums.length;
    
//     for (let i=0; i<k; i++){
//         nums.unshift(nums.pop());
//     }

    nums.unshift(...nums.splice(nums.length-k, k))
};