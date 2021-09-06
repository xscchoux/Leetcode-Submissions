/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    if (!tokens.length) return 0;
    let left = 0, right = tokens.length-1, res = 0;
    tokens.sort(function(a,b){
        return a-b;
    });
    
    while (left <= right && power >= tokens[left]){
        power -= tokens[left];
        res++;left++;
    }
    
    if (res > 0){
        while (left < right){
            power += tokens[right];
            res--; right--;
            while (left <= right && power>=tokens[left]){
                power -= tokens[left];
                res++;left++;
            }
        }
    }
    
    return res;
};