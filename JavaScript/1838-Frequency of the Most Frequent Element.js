/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxFrequency = function(nums, k) {
    nums.sort(function(a,b){return a-b;});
    let res = 1, left = 0, toAdd = 0;
    
    for (let i=1; i<nums.length; i++){
        toAdd += (nums[i]-nums[i-1])*(i-left);
        while (toAdd > k){
            toAdd -= (nums[i]-nums[left]);
            left += 1;
        }
        res = Math.max(res, i-left+1);
    }
    return res;
};