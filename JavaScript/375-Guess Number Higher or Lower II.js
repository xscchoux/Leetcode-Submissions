/**
 * @param {number} n
 * @return {number}
 */
var getMoneyAmount = function(n) {
    
    let memo = new Map();
    let helper = (left, right) =>{
        if (left >= right) return 0;
        if (memo.has(`${left}-${right}`)) return memo.get(`${left}-${right}`);
        let tmp = Number.POSITIVE_INFINITY;
        for (let k=left; k<right; k++){
            tmp = Math.min(tmp, k + Math.max(helper(left, k-1), helper(k+1, right)) )
        }
        memo.set(`${left}-${right}`, tmp);
        return tmp;
    }
    
    return helper(1,n);
};