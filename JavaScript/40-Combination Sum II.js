/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort(function(a,b){return a-b;});
    // console.log(candidates)
    let res = [];
    
    let dfs = (start, val, remain) =>{
        if (remain < 0) return;
        if (remain === 0) res.push(val);
        for (let i=start; i < candidates.length; i++){
            if (i > start && candidates[i] === candidates[i-1]) continue;
            if (remain < candidates[i]) break;
            dfs(i+1, val.concat([candidates[i]]), remain-candidates[i]);
        }
    }
    dfs(0, [], target);
    return res;
};