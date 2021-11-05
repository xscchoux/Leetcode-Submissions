/**
 * @param {number[][]} room
 * @return {number}
 */
var numberOfCleanRooms = function(room) {
    const row = room.length, col = room[0].length;
    let res = 1, currR = 0, currC = 0, state = 0;
    directions = [[0,1],[1,0],[0,-1],[-1,0]];
    room[0][0] = -1;
    let used = new Set();
    used.add((0,0,0));
    
    while (true){
        [dr, dc] = directions[state];
        let [nxtR, nxtC] = [currR+dr, currC+dc];
        if (nxtR<0 || nxtR>=row || nxtC<0 || nxtC>=col || room[nxtR][nxtC] === 1){
            state = (state+1)%4;
        }else{
            if (room[nxtR][nxtC] === 0){
                res += 1;
                room[nxtR][nxtC] = -1;
            }
            [currR, currC] = [nxtR, nxtC];
        }
        if (!used.has(`${currR}-${currC}-${state}`)){
            used.add(`${currR}-${currC}-${state}`);
        }else{
            return res;
        }
    }
};