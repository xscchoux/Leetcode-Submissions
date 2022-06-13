class Solution(object):
    def distinctNames(self, ideas):
        """
        :type ideas: List[str]
        :rtype: int
        """
# https://www.youtube.com/watch?v=DuUxLAikrIE
        hmap = collections.defaultdict(set)
        
        for idea in ideas:
            hmap[idea[0]].add(idea[1:])
        
        string ="abcdefghijklmnopqrstuvwxyz"
        res = 0
        
        for i in range(26):
            for j in range(i+1, 26):
                l1, l2 = len(hmap[string[i]]), len(hmap[string[j]])
                if l1 == 0 or l2 == 0:
                    continue
                common = 0
                for s in hmap[string[j]]:
                    if s in hmap[string[i]]:
                        common += 1
                res += (l1-common)*(l2-common)*2
                
        return res