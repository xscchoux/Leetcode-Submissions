/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number}
 */
var findMaxValueOfEquation = function(points, k) {
    let res = Number.NEGATIVE_INFINITY;
    let queue = [];
    
    for (let [x, y] of points){
        while (queue.length && x - queue[0][1] > k){
            queue.shift();
        }
        if (queue.length){
            res = Math.max(res, x + y + queue[0][0]);
        }
        while (queue.length && y-x > queue[queue.length-1][0]){
            queue.pop();
        }
        queue.push([y-x, x]);
    }
    return res;
};