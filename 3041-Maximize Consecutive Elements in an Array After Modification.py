class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        hmap = defaultdict(int)
        nums.sort(reverse = True)
        for num in nums:
            hmap[num] = max(hmap[num], 1)
            if num+1 in hmap:
                hmap[num] = hmap[num+1] + 1

            hmap[num+1] = max(hmap[num+1], 1)
            if num+2 in hmap:
                hmap[num+1] = hmap[num+2] + 1

        return max(hmap.values())