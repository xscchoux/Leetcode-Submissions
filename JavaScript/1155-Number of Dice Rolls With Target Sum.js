/**
 * @param {number} d
 * @param {number} f
 * @param {number} target
 * @return {number}
 */
var numRollsToTarget = function(d, f, target) {
    const kMod = 1000000007;
    let memo = new Map();
    let dfs = (dice, targetRemain) =>{
        if (dice === 0){
            if (targetRemain === 0) return 1;
            return 0;
        }
        
        if (dice*f < targetRemain || targetRemain < dice){
            return 0;
        }
        
        if (memo.has(`${dice}-${targetRemain}`) ){
            return memo.get(`${dice}-${targetRemain}`);
        }
        
        let res = 0;
        for (let nxt = 1; nxt <= f; nxt++){
            if (nxt > targetRemain) break;
            res = (res + dfs(dice-1, targetRemain-nxt))%kMod;
        }
        memo.set(`${dice}-${targetRemain}`, res)
        return res;
    }
    return dfs(d, target);
};
