/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var findDiagonalOrder = function(nums) {
    let res = [];
    for (let i=0; i<nums.length; i++){
        for (let j=0; j<nums[i].length; j++){
            if (i+j >= res.length){
                res.push([]);
            }
            res[i+j].unshift(nums[i][j]);
        }
    }
    
    return res.flat();
};