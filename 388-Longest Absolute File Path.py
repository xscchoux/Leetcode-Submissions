class Solution:
    def lengthLongestPath(self, input: str) -> int:
        arr = input.split('\n')
        hmap = defaultdict(int)
        res = 0

        for data in arr:
            numTab, idx= 0, 0
            stripped = data.lstrip("\t")
            numTab = len(data) - len(stripped)

            if numTab == 0:
                hmap[numTab] = len(data)
            else:
                hmap[numTab] = hmap[numTab-1] + 1 + len(stripped)
            if "." in data:
                res = max(res, hmap[numTab])

        return res