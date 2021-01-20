/**
 * @param {number[]} jobs
 * @param {number} k
 * @return {number}
 */
var minimumTimeRequired = function(jobs, k) {
    let n = jobs.length;
    let buckets = new Array(k).fill(0);
    let res = Number.POSITIVE_INFINITY;

    let backtrack = (index) =>{
        // console.log(res);
        if (index === n){
            res = Math.min(res, Math.max(...buckets));
        }else{
            for (let i=0; i<k; i++){
                if (buckets[i] + jobs[index] < res){
                    buckets[i] += jobs[index];
                    backtrack(index+1);
                    buckets[i] -= jobs[index];
                }
                if (buckets[i] === 0){
                    break;
                }
            }
        }
    }
    backtrack(0);
    return res;
};