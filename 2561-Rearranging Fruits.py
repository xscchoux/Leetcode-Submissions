class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
# https://leetcode.com/problems/rearranging-fruits/discuss/3144124/PYTHON-O(N-log-N)-Count-and-Sorting-Solution
        tot = collections.Counter(basket1+basket2)
        if not all(v%2==0 for v in tot.values()):
            return -1

        hmap1, hmap2 = collections.Counter(basket1), collections.Counter(basket2)
        arr1, arr2 = [], []
        
        for k in tot.keys():
            if hmap1[k] > hmap2[k]:
                diff = hmap1[k] - hmap2[k]
                for _ in range(diff//2):
                    arr1.append(k)
            
            elif hmap1[k] < hmap2[k]:
                diff = hmap2[k] - hmap1[k]
                for _ in range(diff//2):
                    arr2.append(k)

        res = 0
        minValue = min(min(basket1), min(basket2))
        arr1.sort()
        arr2.sort(reverse=True)
        
        for i in range(len(arr1)):
            res += min(arr1[i], arr2[i], minValue*2)
        
        return res