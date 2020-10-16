/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let res = 0;
    let stack = [];
    for (let i=0; i<height.length; i++){
        while (stack.length>0 && height[i] > height[stack[stack.length-1]]){
            let currIndex = stack.pop();
            if (stack.length>0){
                let h = Math.min(height[i], height[stack[stack.length-1]]) - height[currIndex];
                let w = i - stack[stack.length-1] - 1;
                res += h*w
            }
        }
        stack.push(i);
    }
    return res;
};