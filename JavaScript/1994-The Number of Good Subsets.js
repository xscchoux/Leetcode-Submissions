/**
 * @param {number[]} nums
 * @return {number}
 */
 // https://www.youtube.com/watch?v=bV5LgQH9ERQ
var numberOfGoodSubsets = function(nums) {
    const kMod = BigInt(1000000007);
    const primes = [2,3,5,7,11,13,17,19,23,29];
    let count = new Map();
    
    for (let num of nums){
        if (!count.has(num)){
            count.set(num, 1n);
        }else{
            count.set(num, count.get(num)+1n);
        }
    }
    
    const keys = [...count.keys()];
    N = keys.length;
    
    let dp = (ind, mask) =>{
        if (ind === N) return 1n;
        let ans = dp(ind+1, mask);
        let num = keys[ind];
        
        if (num !== 1 && num%4 !== 0 && num%9 !== 0 && num !== 25){
            let currMask = 0;
            for (let i=0; i<primes.length; i++){
                if (num%primes[i] === 0){
                    currMask += (1<<i);
                }
            }
            if ((currMask&mask) === 0){
                ans += dp(ind+1, mask|currMask )*count.get(num);
                ans%=kMod
            }
        }
        return ans;
    }
    
    let power = BigInt(1);
    for (let i=1; i<=count.get(1)||0; i++){
        power = (power*2n)%kMod;
    }
    
    return (dp(0,0)-1n)*power%kMod;
};
