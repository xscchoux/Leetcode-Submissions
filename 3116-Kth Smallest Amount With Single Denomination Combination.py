class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        # time complexity: log(k) * 2^n * klog(max value in coins)
        # https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/solutions/5019504/python3-math-inclusion-exclusion-principle-binary-search/
        
        N = len(coins)
        hmap = defaultdict(list)
        
        for i in range(1, N+1):
            for comb in itertools.combinations(coins, i):
                hmap[i].append(math.lcm(*comb))

        def isOK(maxVal):
            cnt = 0
            for i in range(1, N+1):
                for lcmVal in hmap[i]:
                    cnt += (maxVal//lcmVal)*pow(-1, i+1)
            return cnt >= k

        left, right = min(coins), min(coins)*k

        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid

        if isOK(left):
            return left
        return right