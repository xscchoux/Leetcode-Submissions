/**
 * @param {number[]} nums
 * @return {number}
 */

// Sol1
var findDuplicate = function(nums) {
    let visited = new Set();
    for (let num of nums){
        if (visited.has(num)) return num;
        else visited.add(num)
    }
};

// Sol2
var findDuplicate = function(nums) {
    let slow = nums[0], fast = nums[slow];
    while (slow !== fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (fast === slow){
            fast = 0;
            while (slow !== fast){
                slow = nums[slow];
                fast = nums[fast];
            }
        }
    }
    return fast;
};