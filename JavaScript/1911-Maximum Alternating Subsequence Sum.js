/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAlternatingSum = function(nums) {
    
// DFS + memoization
    let memo = new Map();
    const N = nums.length;
    
    let dfs = (index, isEven) =>{
        if (index === N) return 0;
        if (memo.has(`${index}-${isEven}`)) return memo.get(`${index}-${isEven}`);
        let curr = (isEven)? nums[index]: -nums[index];
        memo.set(`${index}-${isEven}`, Math.max(dfs(index+1, isEven), curr + dfs(index+1, !isEven)) );
        return memo.get(`${index}-${isEven}`);
    }
    
    return dfs(0, true);

// DP
    let maxEven = nums[0], maxOdd = 0;
    for (let i=1; i<nums.length; i++){
        [maxEven, maxOdd] = [Math.max(maxEven, maxOdd + nums[i]), Math.max(maxOdd, maxEven - nums[i] )];
    }
    return Math.max(maxEven, maxOdd);
};