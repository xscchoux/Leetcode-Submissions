/**
 * @param {number[]} heights
 * @return {number[]}
 */
var canSeePersonsCount = function(heights) {
    const N = heights.length;
    let res = new Array(N).fill(0);
    let stack = new Array();
    
    for (let i=0; i<N; i++){
        while (stack.length && heights[i] >= heights[stack[stack.length-1]]){
            res[stack.pop()] += 1;
        }
        if (stack.length){
            res[stack[stack.length-1]] += 1;
        }
        stack.push(i);
    }
    return res;
};