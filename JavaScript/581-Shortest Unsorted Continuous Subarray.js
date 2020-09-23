/**
 * @param {number[]} nums
 * @return {number}
 */
 
// sorting
var findUnsortedSubarray = function(nums) {
    let clone = [].concat(nums)
    clone.sort(function(a,b){return a-b;});
    let start = clone.length, end = 0;
    
    for (let i=0; i<clone.length; i++){
        if (clone[i] !== nums[i]){
            start = Math.min(i, start);
            end = Math.max(i, end);
        }
    }
    return end-start >=0? end-start+1:0;
};

// stack
var findUnsortedSubarray = function(nums) {
    let stack = [];
    let left = nums.length, right = 0;
    
    for (let i=0; i<nums.length; i++){
        while(stack.length !== 0 && nums[i] < nums[stack[stack.length-1]]){
            left = Math.min(left, stack.pop());
        }
        stack.push(i);
    }
    
    stack = [];
    
    for (let i=nums.length-1; i>=0; i--){
        while(stack.length !==0 && nums[i] > nums[stack[stack.length-1]]){
            right = Math.max(right, stack.pop());
        }
        stack.push(i)
    }
    return right - left > 0 ? right - left + 1: 0;
};