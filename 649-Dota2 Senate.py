class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        N = len(senate)
        rQueue, dQueue = deque(), deque()
        
        for i, c in enumerate(senate):
            if c == "R":
                rQueue.append(i)
            else:
                dQueue.append(i)
        
        while rQueue and dQueue:
            nxtR = rQueue.popleft()
            nxtD = dQueue.popleft()
            
            if nxtR < nxtD:
                rQueue.append(nxtR+N)
            else:
                dQueue.append(nxtD+N)
        
        return "Radiant" if rQueue else "Dire"