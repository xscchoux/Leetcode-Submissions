/**
 * @param {string} s
 * @return {number}
 */
var maxProduct = function(s) {
    const N = s.length;
    let res = 0;
    
    let cal = (state) =>{
        let string = "";
        for (let j=0; j<N; j++){
            if ( (state>>j)&1 ){
                string += s[j];
            }
        }
        const Nstring = string.length;
        let dp = new Array(Nstring).fill().map(()=>new Array(Nstring).fill(0));
        for (let i=0; i<Nstring; i++){
            dp[i][i] = 1;
        }
        for (let length=2; length<=Nstring; length++){
            for (let start=0; start<=Nstring-length; start++){
                let end = start + length-1;
                if (string[start] === string[end]){
                    dp[start][end] = dp[start+1][end-1] + 2;
                }else{
                    dp[start][end] = Math.max(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][Nstring-1];
        
    }
    
    for (let state=1; state<(1<<N)-1; state++){
        res = Math.max(res, cal(state)*cal((1<<N)-1-state) );
    }
    
    return res;
};