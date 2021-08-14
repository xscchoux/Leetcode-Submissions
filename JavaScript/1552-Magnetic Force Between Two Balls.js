/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function(position, m) {
    const N = position.length;
    
    position.sort(function(a,b){
        return a-b;
    })
    
    let putBalls = (diff) =>{
        let count = 1, prev = position[0];
        for (let i=1; i<N; i++){
            if (position[i] - prev >= diff){
                count++;
                if (count === m) return true;
                prev = position[i];
            }
        }
        return false;
    }
    
    let left = 1, right = Math.floor((position[N-1] - position[0])/(m-1));
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (putBalls(mid)){
            left = mid;
        }else{
            right = mid;
        }  
    }
    
    if (putBalls(right)){
        return right;
    }else{
        return left;
    }
};