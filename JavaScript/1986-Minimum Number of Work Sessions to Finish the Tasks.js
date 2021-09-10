/**
 * @param {number[]} tasks
 * @param {number} sessionTime
 * @return {number}
 */
var minSessions = function(tasks, sessionTime) {
    const N = tasks.length;
    let memo = new Map();
    
    let dp = (state) =>{
        if (state === 0) return [0, 0];
        if (memo.has(state)) return memo.get(state);
        
        let sessionCurr = N + 1, remainCurr = 0;
        
        for (let i=0; i<N; i++){
            if ( (state>>i)&1 ){
                let [sessionNum, remain] = dp( state^(1<<i) );
                
                if (tasks[i]<=remain){
                    remain -= tasks[i];
                }else{
                    remain = sessionTime-tasks[i];
                    sessionNum += 1;
                }
                if (sessionNum < sessionCurr || (sessionNum===sessionCurr && remain > remainCurr) ){
                    sessionCurr = sessionNum;
                    remainCurr = remain;
                }
            }
        }
        memo.set(state, [sessionCurr, remainCurr]);
        return [sessionCurr, remainCurr];
    }
    
    return dp( (1<<N)-1)[0];
};