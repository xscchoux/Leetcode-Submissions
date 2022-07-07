class Solution(object):
    def maxBoxesInWarehouse(self, boxes, warehouse):
        """
        :type boxes: List[int]
        :type warehouse: List[int]
        :rtype: int
        """
        mn = warehouse[0]
        for i in range(len(warehouse)):
            mn = min(warehouse[i], mn)
            warehouse[i] = mn

        boxes.sort()
        
        ind = len(warehouse)-1
        ind_box = 0
        count = 0
        
        while ind >= 0 and ind_box < len(boxes):
            if boxes[ind_box] <= warehouse[ind]:
                ind -= 1
                ind_box += 1
                count += 1
            else:
                ind -= 1
                
        return count