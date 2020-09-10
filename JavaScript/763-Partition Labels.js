/**
 * @param {string} S
 * @return {number[]}
 */
var partitionLabels = function(S) {
    let hmap = {};
    
    for (let i=0; i<S.length; i++){
        hmap[S[i]] = i;
    }
    
    let start = 0, end = 0;
    let res = [];
    for (let j=0; j<S.length; j++){
        end = Math.max(end, hmap[S[j]]);
        if (j === end){
            res.push(end-start+1);
            start = end + 1;
        }
    }
    return res;
};