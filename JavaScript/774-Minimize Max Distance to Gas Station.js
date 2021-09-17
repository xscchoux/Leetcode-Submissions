/**
 * @param {number[]} stations
 * @param {number} k
 * @return {number}
 */
var minmaxGasDist = function(stations, k) {
    let left = 0, right = Math.max(...stations);
    let canAdd = (dist) =>{
        let res = 0;
        for (let i=1; i<stations.length; i++){
            res += Math.floor( (stations[i]-stations[i-1])/dist );
            if (res > k) return false;
        }
        return true;
    }
    
    while (left + Math.pow(10,-6) <= right){
        mid = left + (right-left)/2;
        if (canAdd(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
};