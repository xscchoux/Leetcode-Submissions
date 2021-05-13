/**
 * @param {number[][]} costs
 * @return {number}
 */
var minCostII = function(costs) {
    
    let n = costs.length, k = costs[0].length;
    
    if (k === 1 && n > 1){
        return 2147483647;
    }
    
    for (let house = 1; house < n; house++){
        let min1Color = -1, min2Color = -1;
        for (let color = 0; color < k; color++){
            if(min1Color === -1 || costs[house-1][color] < costs[house-1][min1Color]){
                min2Color = min1Color;
                min1Color = color;
            }else if(min2Color === -1 || costs[house-1][color] < costs[house-1][min2Color]){
                min2Color = color;
            }
        }
        for (let color = 0; color < k; color++){
            if (color === min1Color){
                costs[house][color] += costs[house-1][min2Color];
            }else{
                costs[house][color] += costs[house-1][min1Color];
            }
        }
    }
    return Math.min(...costs[costs.length-1]);
};