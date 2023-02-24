class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        curr = 1
        time = 1
        while curr <= memory1 or curr <= memory2:
            if memory1 >= memory2:
                memory1 -= curr
            else:
                memory2 -= curr
            time += 1
            curr += 1
            
        return [time, memory1, memory2]