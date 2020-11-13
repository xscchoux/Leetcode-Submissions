/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    let stack = [];
    let hmap = new Map();
    
    for (let num of nums2){
        while(stack.length && num > stack[stack.length-1]){
            hmap.set(stack.pop(), num);
        }
        stack.push(num);
    }
    let res = [];
    for (let num of nums1){
        if (!hmap.get(num)){
            res.push(-1);
        }else{
            res.push(hmap.get(num));
        }
    }
    return res;
};