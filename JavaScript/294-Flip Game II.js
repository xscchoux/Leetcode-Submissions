/**
 * @param {string} s
 * @return {boolean}
 */
var canWin = function(s) {
    let memo = new Map();
    
    let dfs = (s) =>{
        if (memo.has(s)) return memo.get(s);
        for (let i=0; i<s.length-1; i++){
            if (s[i] === '+' && s[i+1] === '+'){
                if (!dfs(s.substring(0,i) + '--' + s.substring(i+2))){
                    memo.set(s, true);
                    return true;
                }
            }
        }
        memo.set(s, false);
        return false;
    }
    return dfs(s);
};