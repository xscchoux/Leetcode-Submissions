class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        count = Counter(zip(*grid))
        return sum(count[tuple(row)] for row in grid)