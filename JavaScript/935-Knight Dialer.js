/**
 * @param {number} n
 * @return {number}
 */
var knightDialer = function(n) {
    const kMod = 1000000007;
    let x = new Array(10).fill(1);
    for (let i=2; i<=n; i++){
        let newX = new Array(n+1);
        newX[0] = (x[4] + x[6])%kMod;
        newX[1] = (x[6] + x[8])%kMod;
        newX[2] = (x[7] + x[9])%kMod;
        newX[3] = (x[4] + x[8])%kMod;
        newX[4] = (x[0] + x[3] + x[9])%kMod;
        newX[5] = 0;
        newX[6] = (x[0] + x[1] + x[7])%kMod;
        newX[7] = (x[2] + x[6])%kMod;
        newX[8] = (x[1] + x[3])%kMod;
        newX[9] = (x[2] + x[4])%kMod;
        x = newX;
    }
    return x.reduce(function(x, acc){return x+acc;}, 0)%kMod;
};