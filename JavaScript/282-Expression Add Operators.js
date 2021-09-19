/**
 * @param {string} num
 * @param {number} target
 * @return {string[]}
 */
var addOperators = function(num, target) {
    const N = num.length;
    let res = [];
    let dfs = (start, expression, prevSum, toMultiply) =>{
        if (start === N){
            if (prevSum === target){
                res.push(expression);
            }
            return;
        }
        for (let i=start+1; i<=N; i++){
            if (num[start] === "0" && i-start > 1) break;    
            let curr = parseInt(num.substring(start, i));
            if (start === 0){
                dfs(i, curr.toString(), curr, curr);
            }else{
                dfs(i, expression+"-"+curr.toString(), prevSum-curr, -1*curr);
                dfs(i, expression+"+"+curr.toString(), prevSum+curr, curr);
                dfs(i, expression+"*"+curr.toString(), prevSum-toMultiply+curr*toMultiply, curr*toMultiply);       
            }

        }
    }
    dfs(0, "", 0, 0);
    return res;
};