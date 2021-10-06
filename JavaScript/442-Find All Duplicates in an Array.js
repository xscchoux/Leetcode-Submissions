/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let res = new Array();
    for (let i=0; i<nums.length; i++){
        let num = Math.abs(nums[i]);
        if (nums[num-1] < 0){
            res.push(num);
        }else{
            nums[num-1] *= -1;
        }
    }
    return res;
};