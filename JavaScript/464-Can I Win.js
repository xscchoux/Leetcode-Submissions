/**
 * @param {number} maxChoosableInteger
 * @param {number} desiredTotal
 * @return {boolean}
 */
var canIWin = function(maxChoosableInteger, desiredTotal) {
    if (maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal){
        return false;
    }
    if (desiredTotal === 0){
        return true;
    }
    
    let picked = 0;
    memo = new Map();
    
    let helper = (remain, bitmask) =>{
        if (remain <= 0){
            return false;
        }
        
        if (memo.has(bitmask)){
            return memo.get(bitmask);
        }
        
        for (let i=1; i<=maxChoosableInteger; i++){
            if( (1<<(i-1))& bitmask ){
                continue;
            }
            if (!helper(remain-i, bitmask | (1<<(i-1)))){
                memo.set(bitmask, true);
                return true;        
            }
        }
        memo.set(bitmask, false);
        return false;
    }
    return helper(desiredTotal, picked);
};