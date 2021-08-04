/**
 * @param {number} neededApples
 * @return {number}
 */
var minimumPerimeter = function(neededApples) {
    let count = (n) =>{
        return 2*n*(n+1)*(2*n+1);
    }
    let left = 1, right = Math.pow(10, 7);
    
    while (left + 1 < right){
        let mid = left + Math.floor( (right-left)/2 );
        if (count(mid) >= neededApples){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    if (count(left)>=neededApples){
        return 8*left;
    }else{
        return 8*right;
    }
};