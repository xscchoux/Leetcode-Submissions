/**
 * @param {string} s
 * @param {number[]} answers
 * @return {number}
 */
var scoreOfStudents = function(s, answers) {
    let correct = 0;
    for (let toAdd of s.split("+")){
        let multiplied = 1
        for (let toMulti of toAdd.split("*")){
            multiplied *= parseInt(toMulti);
        }
        correct += multiplied;
    }

    const operator = {
        "+": ((a,b)=>a+b),
        "*": ((a,b)=>a*b)
    } 
    
    dp = new Array(30).fill().map(()=>new Array(30));
    
    let cal = (start, end) =>{
        if (start === end){
            return [parseInt(s[start])];
        }
        if (dp[start][end]){
            return dp[start][end];
        }
        let res = new Set();
        for (let i=start; i<=end; i++){
            const current = s[i];
            if (isNaN(current)){
                let left = cal(start, i-1), right = cal(i+1, end);
                for (let l of left){
                    for (let r of right){
                        let z = operator[current](l, r);
                        if (z <= 1000) res.add(operator[current](l, r));
                    }
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
    
    other = cal(0, s.length-1);
    let ans = 0;
    
    for (let answer of answers){
        if (answer === correct){
            ans+=5;
        }else if(other.has(answer)){
            ans+=2;
        }
    }
    return ans;
};