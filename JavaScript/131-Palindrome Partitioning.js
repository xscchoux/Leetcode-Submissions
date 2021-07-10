/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    const N = s.length;
    let memo = new Map();
    
    let isPalindrome = (left, right) =>{
        while (left < right){
            if (s[left]!==s[right]) return false;
            left++;right--;
        }
        return true;
    }
    
    let dfs = (start) =>{
        if (N-1 < start){
            return [[]];
        }
        if (memo.has(start)){
            return memo.get(start);
        }
        let curr = new Array();
        for (let i=start; i<N; i++){
            if (isPalindrome(start, i)){
                let currSub = s.substring(start,i+1);
                for (let arr of dfs(i+1)){
                    curr.push([currSub].concat(arr));
                }
            }
        }
        memo.set(start, curr);
        return curr;
    }
    return dfs(0, N-1)
};