/**
 * @param {number[][]} costs
 * @return {number}
 */
var minCost = function(costs) {
    const n = costs.length;
    
    for (let i=1; i<n; i++){
        for (let j=0; j<3; j++){
            costs[i][j] += Math.min(costs[i-1][((j-1)+3)%3], costs[i-1][(j+1)%3]);
        }
    }
    
    return Math.min(...costs[costs.length-1]);
};