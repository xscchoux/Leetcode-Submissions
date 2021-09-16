/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
var mincostTickets = function(days, costs) {
    const N = days.length;
    const dayPass = [1, 7, 30];
    let memo = new Map();

    let dp = (i) =>{
        if (i >= N) return 0;
        if ( memo.has(i) ){
            return memo.get(i);
        }
        
        let nxtIdx = i, res = Number.POSITIVE_INFINITY;
        for (let j=0; j<costs.length; j++){
            while (nxtIdx < N && days[nxtIdx] < (dayPass[j] + days[i]) ){
                nxtIdx++;
            }
            res = Math.min(res, costs[j] + dp(nxtIdx));
        }
        memo.set(i, res);
        return res;
    }
    
    return dp(0);
};