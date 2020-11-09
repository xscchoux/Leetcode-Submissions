/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    let res = [];
    let stack = [];
    for (let i=0; i<nums.length; i++){
        while (stack.length && nums[i] > nums[stack[stack.length-1]]){
            stack.pop();
        }
        stack.push(i)
        if (i < k-1){
            continue;
        }
        if (i - stack[0] === k){
            stack.shift();
        }
        res.push(nums[stack[0]]);
    }
    return res;
};