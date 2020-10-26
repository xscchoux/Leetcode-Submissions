/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let stack = [];
    let res = 0;
    heights.push(-1);
    for (let i=0; i<heights.length; i++){
        while (stack.length >0 && heights[i] < heights[stack[stack.length-1]] ){
            let heightIndex = stack.pop();
            let w = 0;
            if (stack.length > 0){
                w = i - stack[stack.length-1] - 1;
            }
            else{
                w = i;
            }
            res = Math.max(res, w*heights[heightIndex]);
        }
        stack.push(i)
    }
    return res;
};