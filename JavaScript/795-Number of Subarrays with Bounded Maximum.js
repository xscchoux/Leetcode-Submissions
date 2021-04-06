/**
 * @param {number[]} A
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var numSubarrayBoundedMax = function(A, L, R) {
    
    let findSub = (bound) =>{
        let curr = 0, res = 0;
        for (let val of A){
            if (val <= bound){
                curr += 1;
                res += curr;
            }else{
                curr = 0;
            }
        }
        return res;
    }
    return findSub(R) - findSub(L-1);
};