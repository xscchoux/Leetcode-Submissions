/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function(target, position, speed) {
    let arr = new Array();
    for(let i=0;i<position.length;i++)
        arr.push({pos:position[i], spd:speed[i]});
    
    arr.sort((a,b)=>b.pos-a.pos);
    
    let prevTime = 0, ans = 0;
    
    for (let i=0; i<arr.length; i++){
        let time = (target-arr[i].pos)/arr[i].spd;
        if (time > prevTime){
            ans += 1;
            prevTime = time;
        }
    }
    return ans;
};