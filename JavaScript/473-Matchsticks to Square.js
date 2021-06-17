/**
 * @param {number[]} matchsticks
 * @return {boolean}
 */
var makesquare = function(matchsticks) {
    if (matchsticks.length < 4) return false;
    const total = matchsticks.reduce((acc, x)=>acc+x);
    if (total%4) return false;
    const sideLen = total/4;
    let memo = new Map();
    
    let dfs = (bitmask, remain, completed) =>{
        if (bitmask === 0 && completed === 4) return true;
        if (memo.has(`${bitmask}-${remain}-${completed}`)){
            return memo.get(`${bitmask}-${remain}-${completed}`)
        }
        
        let ans = false;
        for (let i=0; i<matchsticks.length; i++){
            if (bitmask & (1<<i) && matchsticks[i] <= remain){
                if (matchsticks[i] < remain){
                    if (dfs(bitmask ^ (1<<i), remain-matchsticks[i], completed)){
                        ans = true;
                        break;
                    }
                }else{
                    if (dfs(bitmask ^ (1<<i), sideLen, completed+1)){
                        ans = true;
                        break;
                    }
                }
            }
        }
        memo.set(`${bitmask}-${remain}-${completed}`, ans);
        return ans;
    }
    return dfs( (1<<matchsticks.length)-1, sideLen, 0 )
};