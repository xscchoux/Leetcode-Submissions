class Solution(object):
    def numberOfCleanRooms(self, room):
        """
        :type room: List[List[int]]
        :rtype: int
        """
        row = len(room)
        col = len(room[0])
        
        currR, currC = 0, 0
        room[0][0] = -1
        directions = [(0,1), (1,0), (0,-1), (-1,0)]
        state = 0
        res = 1
        used = set()
        used.add((0,0,0))
        
        while True:
            dr, dc = directions[state]
            nxtR, nxtC = currR+dr, currC+dc
            if nxtR >= row or nxtR < 0 or nxtC < 0 or nxtC >= col or room[nxtR][nxtC] == 1:
                state = (state + 1)%4
            else:
                currR, currC = nxtR, nxtC
                if room[currR][currC] == 0:
                    res += 1
                    room[currR][currC] = -1
                
            if (currR, currC, state) not in used:
                used.add((currR, currC, state))
            else:
                return res