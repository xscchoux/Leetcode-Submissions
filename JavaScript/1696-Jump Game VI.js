/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxResult = function(nums, k) {
    stack = [0];
    
    for (let i=1; i<nums.length; i++){
        if (i-k > stack[0]){
            stack.shift();
        }
        nums[i] += nums[stack[0]];
        while (stack.length && nums[i] > nums[stack[stack.length-1]]){
            stack.pop();
        }
        stack.push(i);
    }

    return nums[nums.length-1];
};