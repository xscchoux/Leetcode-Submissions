/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
    if (A.length !== B.length || A.length <=1) return false;
    if (A === B){
        let seen = new Set()
        for (let a of A){
            if (seen.has(a)) return true;
            seen.add(a)
        }
        return false;
    } else{
        let mismatch = [];
        for (let i=0; i<A.length; i++){
            if (A[i]!==B[i]) mismatch.push(i)
        }
        return mismatch.length === 2 && A[mismatch[0]] === B[mismatch[1]] && B[mismatch[0]] === A[mismatch[1]]
    }
};