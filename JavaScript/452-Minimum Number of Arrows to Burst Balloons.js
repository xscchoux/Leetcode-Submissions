/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    points.sort(function(a,b){
        return a[1]-b[1];
    })
    
    let res = 0;
    let lastEnd = Number.NEGATIVE_INFINITY;
    
    for (let [start, end] of points){
        if (start > lastEnd){
            res++;
            lastEnd = end;
        }
    }
    
    return res;
};