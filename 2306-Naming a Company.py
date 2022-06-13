class Solution(object):
    def distinctNames(self, ideas):
        """
        :type ideas: List[str]
        :rtype: int
        """
# https://www.youtube.com/watch?v=DuUxLAikrIE
        hmap = collections.defaultdict(set)
        string = set()
        for idea in ideas:
            hmap[idea[0]].add(idea[1:])
            string.add(idea[0])

        res = 0
        arr = list(string)
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                l1, l2 = len(hmap[arr[i]]), len(hmap[arr[j]])
                common = 0
                for s in hmap[arr[j]]:
                    if s in hmap[arr[i]]:
                        common += 1
                res += (l1-common)*(l2-common)*2
                
        return res