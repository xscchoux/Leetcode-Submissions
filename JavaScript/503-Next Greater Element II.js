/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function(nums) {
    let N = nums.length;
    let stack = [];
    let res = new Array(N).fill(-1);
    
    for (let i=0; i<2*N-1; i++){
        let currNum = nums[i%N];
        while(stack.length && currNum > nums[stack[stack.length-1]]){
            res[stack.pop()] = currNum;
        }
        if(i<N){
            stack.push(i);
        }
    }
    return res;
};