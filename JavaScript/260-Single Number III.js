/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    let bitmask = 0;
    for (let num of nums){
        bitmask = bitmask^num;
    }
    
    const diff = bitmask&(-bitmask);
    let x = 0;
    for (let num of nums){
        if (num & diff){
            x = x^num;
        }
    }
    
    return [x, bitmask^x];
};