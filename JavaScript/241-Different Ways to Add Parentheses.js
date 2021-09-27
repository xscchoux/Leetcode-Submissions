/**
 * @param {string} expression
 * @return {number[]}
 */
var diffWaysToCompute = function(expression) {
    let dp = new Array(21).fill().map(()=>new Array());

    let cal = (start, end) =>{
        if (dp[start][end] != undefined){
            return dp[start][end];
        }
        
        // isNaN(num) returns true if the variable does NOT contain a valid number
        
        if (!isNaN(expression.substring(start, end+1))){
            return [parseInt(expression.substring(start, end+1))];
        }
        
        let res = [];
        for (let i=start; i<=end; i++){
            const current = expression[i];
            if (isNaN(parseInt(current,10))){
                let left = cal(start, i-1), right = cal(i+1, end);
                for (let l of left){
                    for (let r of right){
                        if (current === "+"){
                            res.push(parseInt(l) + parseInt(r));
                        }else if (current === "-"){
                            res.push(parseInt(l) - parseInt(r));
                        }else{
                            res.push(parseInt(l) * parseInt(r));
                        }
                    }
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
    return cal(0, expression.length-1);
};