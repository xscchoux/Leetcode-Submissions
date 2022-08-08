class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        
        hmap = collections.defaultdict(int) # type: last time tasks[i] was completed
        breaks = 0
        
        for i in range(len(tasks)):
            if tasks[i] in hmap:
                if i - hmap[tasks[i]] - 1 + breaks < space:
                    breaks += (space - (i + breaks - hmap[tasks[i]] - 1))
            hmap[tasks[i]] = i + breaks
        
        return len(tasks) + breaks