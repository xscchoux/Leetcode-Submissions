/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(intervals) {
    intervals.sort(function(a,b){
        if (a[0]!==b[0]) return a[0]-b[0];
        else return b[1]-a[1];
    })
    
    let maxi = intervals[0][1];
    len = intervals.length;
    for (let i=1; i<intervals.length; i++){
        if (intervals[i][1] <= maxi) len-=1;
        else{
            maxi = Math.max(intervals[i][1], maxi);            
        }
    }
    return len;
};