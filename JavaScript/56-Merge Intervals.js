/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (!intervals) return [];
    intervals.sort(function(a,b){
        return a[0] - b[0];
    })
    let stack = [];
    for (let i=0; i<intervals.length; i++){
        if (stack.length > 0 && intervals[i][0] <= stack[stack.length-1][1]){
            stack[stack.length-1][1] = Math.max(stack[stack.length-1][1], intervals[i][1]);
        }
        else{
            stack.push(intervals[i]);
        }
    }
    return stack;
};