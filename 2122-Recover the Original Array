class Solution(object):
    def recoverArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        count = collections.Counter(nums)
        for i in range(1, len(nums)//2 + 1):
            diff = nums[i] - nums[0]
            if diff == 0 or diff%2 != 0:
                continue
            
            hmap = count.copy()
            find = True
            res = []
            for num in nums:
                if hmap[num] == 0:
                    continue
                if hmap[num+diff] == 0:
                    find = False
                    break
                hmap[num]-=1
                hmap[num+diff] -= 1
                res.append(num + diff//2)
            if find:
                return res