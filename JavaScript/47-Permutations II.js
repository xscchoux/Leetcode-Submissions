/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort();
    let res = [];
    let used = new Array(nums.length).fill(false);
    
    let dfs = (val) =>{
        if (val.length === nums.length){
            res.push(Array.from(val));
            return;
        }
        for (let i=0; i<nums.length; i++){
            if (i>0 && nums[i] === nums[i-1] && used[i-1] === true) continue;
            if (used[i] == false){
                used[i] = true;
                val.push(nums[i]);
                dfs(val);
                val.pop();
                used[i] = false;
            }
        }
    }
    dfs([]);
    return res;
};