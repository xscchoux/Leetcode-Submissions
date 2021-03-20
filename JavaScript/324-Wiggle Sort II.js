/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
    let N = nums.length;
    nums.sort(function(a,b){return a-b;})
    let copy = [...nums];
    let j = Math.ceil(N/2)-1, k = N-1;
    
    for (let i=0; i<nums.length; i++){
        if (i%2 === 0){
            nums[i] = copy[j--];
        }else{
            nums[i] = copy[k--];
        }
    }
};