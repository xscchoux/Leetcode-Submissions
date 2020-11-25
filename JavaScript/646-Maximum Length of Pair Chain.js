/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function(pairs) {
    pairs.sort(function(a,b){
        return a[1]-b[1];
    })
    let res = 1, end = pairs[0][1];
    for (let i=1; i<pairs.length; i++){
        if(pairs[i][0] > end){
            res += 1;
            end = pairs[i][1]
        }
    }
    return res;
};