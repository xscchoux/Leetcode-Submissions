/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function(trips, capacity) {
    let points = [];
    for (let trip of trips){
        points.push([trip[1], trip[0]]);
        points.push([trip[2], -trip[0]]);
    }
    
    points.sort(function(a,b){
        if (a[0] === b[0]){
            return a[1]-b[1];
        }else{
            return a[0] - b[0];
        }
    })
    
    let val = 0;
    
    for (let i=0; i<points.length; i++){
        val += points[i][1];
        if (val > capacity){
            return false;
        }
    }
    return true;
    
};