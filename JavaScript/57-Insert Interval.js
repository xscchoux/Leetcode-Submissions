/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    
// same as merge interval, O(nlogn)
    intervals = intervals.concat([newInterval])
    intervals.sort(function(a,b){return a[0]-b[0];})
    let stack = [];
    for (let i=0; i<intervals.length; i++){
        if (stack.length > 0 && intervals[i][0] <= stack[stack.length-1][1]){
            stack[stack.length-1][1] = Math.max(intervals[i][1], stack[stack.length-1][1])
        }
        else{
            stack.push(intervals[i])
        }
    }
    return stack;
    
// O(n)
    if (!intervals) return [newInterval];
    let left = 0, right = intervals.length-1;
    while (left < intervals.length && intervals[left][1] < newInterval[0]){
        left++;
    }
    while (right >= 0 && intervals[right][0] > newInterval[1]){
        right--;
    }
    if (left - 1 !== right){
        newInterval[0] = Math.min(intervals[left][0], newInterval[0]);
        newInterval[1] = Math.max(intervals[right][1], newInterval[1]);
    }

    return intervals.slice(0, left).concat([newInterval]).concat(intervals.slice(right+1,intervals.length))
};