/**
 * @param {number[]} nums
 * @return {boolean}
 */
var judgePoint24 = function(nums) {
    
    let find24 = (arr) =>{
        const n = arr.length;
        
        if ( n === 1){
            return Math.abs(arr[0] - 24) < 1e-9;
        }
        
        for (let i=0; i<n-1; i++){
            for (let j=i+1; j<n; j++){
                const newArr = [...arr.slice(0,i), ...arr.slice(i+1,j), ...arr.slice(j+1)];
                if (find24(newArr.concat([arr[i] + arr[j]]))){
                    return true;
                }
                if (find24(newArr.concat([arr[i] - arr[j]]))){
                    return true;
                }
                if (find24(newArr.concat([arr[j] - arr[i]]))){
                    return true;
                }
                if (find24(newArr.concat([arr[i] * arr[j]]))){
                    return true;
                }
                
                if (arr[i] !== 0 && find24([...newArr, arr[j]/arr[i]])){
                    return true;
                }
                
                if (arr[j] !== 0 && find24([...newArr, arr[i]/arr[j]])){
                    return true;
                }
            }
        }
        return false;
    }
    return find24(nums);
};