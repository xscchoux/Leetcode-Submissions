class Solution(object):
    def customSortString(self, order, str):
        """
        :type order: str
        :type str: str
        :rtype: str
        """
        hmap = collections.defaultdict(int)
        N = len(order)
        for i in range(N):
            hmap[order[i]] = N-i
        res = sorted(list(str), key = lambda x: -hmap[x])
        return "".join(res)