/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
    let maxdis = 0;
    let maxi = arrays[0][arrays[0].length-1], mini = arrays[0][0];
    for (let i=1; i<arrays.length; i++){
        maxdis = Math.max(maxdis, maxi - arrays[i][0], arrays[i][arrays[i].length-1] - mini);
        maxi = Math.max(maxi, arrays[i][arrays[i].length-1]);
        mini = Math.min(mini, arrays[i][0]);
    }
    return maxdis;
    
};