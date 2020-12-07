/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    let maxByFar = nums[0];
    let minByFar = nums[0];
    let res = nums[0];
    
    for (let i=1; i<nums.length; i++){
        if (nums[i]>0){
            maxByFar = Math.max(nums[i], nums[i]*maxByFar)
            minByFar = Math.min(nums[i], nums[i]*minByFar)
        }else{
            let tmp = minByFar
            minByFar = Math.min(nums[i], nums[i]*maxByFar)
            maxByFar = Math.max(nums[i], nums[i]*tmp)
        }
        res = Math.max(res, maxByFar);
    }
    return res;
};