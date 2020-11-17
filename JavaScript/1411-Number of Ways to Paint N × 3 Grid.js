/**
 * @param {number} n
 * @return {number}
 */
var numOfWays = function(n) {
    let same = 6, diff = 6;
    let modulo = Math.pow(10,9)+ 7;
    
    for (let i=1; i<n; i++){
        let tmp = same;
        same = (2*diff + 3*same)%modulo;
        diff = (2*diff + 2*tmp)%modulo;
    }
    
    return (same + diff)%modulo;
};