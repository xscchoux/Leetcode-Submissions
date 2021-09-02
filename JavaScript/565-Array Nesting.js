/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayNesting = function(nums) {
    let memo = new Map();
    let res = 1;
    
    let dfs = (index, head) =>{
        if (nums[index] === head) return 0;
        if (memo.has(nums[index])) return memo.get(nums[index]);
        memo.set(nums[index], 1 + dfs(nums[index], head) );
        return memo.get(nums[index]);
    }
    
    for (let i=0; i<nums.length; i++){
        if (!memo.has(nums[i])){
            memo.set(nums[i], 1+ dfs(nums[i], nums[i]));
            res = Math.max(res, memo.get(nums[i]));
        }
    }
    return res;
};