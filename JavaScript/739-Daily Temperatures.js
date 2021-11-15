/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    let res = new Array(temperatures.length).fill(0);
    let stack = new Array();
    for (let i=0; i<temperatures.length; i++){
        while (stack.length && temperatures[i] > temperatures[stack[stack.length-1]] ){
            let prevIdx = stack[stack.length-1];
            res[prevIdx] = i - prevIdx;
            stack.pop();
        }
        stack.push(i);
    }
    return res;
};