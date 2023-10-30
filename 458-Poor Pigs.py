class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        '''
        Buckets layout:

        1 2 3
        4 5 6
        7 8 9

        Pig 1 (rows):
        Interval 1: Test buckets 1, 2, 3
        Interval 2: Test buckets 4, 5, 6

        Pig 2 (columns):
        Interval 1: Test buckets 1, 4, 7
        Interval 2: Test buckets 2, 5, 8
        '''
        
        # states^pigs >= buckets
        # pigs >= log states_(buckets)
        # states**pigs >= buckets
        # use binary search to find pigs
        
        states = minutesToTest // minutesToDie + 1
        left, right = 0, buckets
        while left + 1 < right:
            mid = left + (right-left)//2
            if states**mid < buckets:
                left = mid
            else:
                right = mid
        
        if states**left >= buckets:
            return left
        return right