/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 1) return nums[0];
    
    let dp = (arr) =>{
        let prev2 = 0, prev = 0, curr = 0;
        for (let i=0; i<arr.length; i++){
            curr = Math.max(prev, arr[i] + prev2);
            [prev2, prev] = [prev, curr];
        }
        return curr;
    }
    return Math.max( dp(nums.slice(0, nums.length-1)), dp(nums.slice(1, nums.length)) );
    
};