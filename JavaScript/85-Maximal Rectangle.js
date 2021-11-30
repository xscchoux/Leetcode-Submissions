/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    if (!matrix.length || !matrix[0].length) return 0;
    const row = matrix.length, col = matrix[0].length;
    let arr = new Array(col).fill(0);
    arr.push(-1);
    let ans = 0;
    
    let findMax = () =>{
        let maxArea = 0;
        let stack = new Array();
        for (let i=0; i<arr.length; i++){
            while (stack.length && arr[i]<=arr[stack[stack.length-1]]){
                let heightIdx = stack.pop();
                let width;
                if (stack.length > 0){
                    width = i - stack[stack.length-1] - 1;
                }else{
                    width = i
                }
                maxArea = Math.max(maxArea, arr[heightIdx]*width);
            }
            stack.push(i);
        }
        return maxArea;
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (matrix[r][c] === "1"){
                arr[c] += 1;
            }else{
                arr[c] = 0;
            }
        }
        ans = Math.max(ans, findMax());
    }
    return ans;
};