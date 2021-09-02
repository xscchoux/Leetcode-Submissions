/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number[]} profit
 * @return {number}
 */
var jobScheduling = function(startTime, endTime, profit) {
    const N = startTime.length;
    let jobs = new Array();
    for (let i=0; i<N; i++){
        jobs.push([startTime[i], endTime[i], profit[i]]);
    }
    jobs.sort(function(a,b){
        return a[0] - b[0];
    })
    
    let getNext = (i) =>{
        if (i === N-1) return N;
        let left = i+1, right = N-1;
        while (left+1<right){
            let mid = left + ((right-left)>>1);
            if (jobs[mid][0]>=jobs[i][1]){
                right = mid;
            }else{
                left = mid;
            }
        }
        if (jobs[left][0] >= jobs[i][1]){
            return left;
        }else if(jobs[right][0] >= jobs[i][1]){
            return right;
        }else{
            return N;
        }
    }
    
    let memo = new Map();
    let dfs = (index) =>{
        if (index === N) return 0;
        if (memo.has(index)){
            return memo.get(index);
        }
        let res = 0, nextIdx = getNext(index);
        res = Math.max(jobs[index][2] + dfs(nextIdx), dfs(index+1) );
        memo.set(index, res);
        return res;
    }
    
    return dfs(0);
};