class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Get the entrance of cycle, check solution
        # D(hare) = F + nC + a  (F:entrance to intersection point, C:cycle length, a:from intersection point to the point slow and fast pointer meet)
        # D(tortoise) = F + kC + a
        # 2*D(tortoise) == D(hard) => F + a = (n-2k)C, where n-2k is an integer
        # Now need to go to the intersection point, take F steps
        # F + a + F = (n-2k)C + F
        
        slow = fast = nums[0]
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
                
        start = nums[0]
        while start != fast:
            start = nums[start]
            fast = nums[fast]
            
        return start