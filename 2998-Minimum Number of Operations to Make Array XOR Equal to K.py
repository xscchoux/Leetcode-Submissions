class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        XOR = 0
        for num in nums:
            XOR = XOR^num

        return bin(XOR^k).count("1")    