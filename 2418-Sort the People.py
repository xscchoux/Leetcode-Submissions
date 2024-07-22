class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [c for _, c in sorted(zip(heights, names), reverse=True)]