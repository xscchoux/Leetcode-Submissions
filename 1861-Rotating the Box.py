class Solution(object):
    def rotateTheBox(self, box):
        """
        :type box: List[List[str]]
        :rtype: List[List[str]]
        """
        row = len(box)
        col = len(box[0])
        
        for r in range(row):
            last = col - 1
            for c in range(col-1, -1, -1):
                if box[r][c] == "#":
                    box[r][c] = "."
                    box[r][last] = "#"
                    last -= 1
                elif box[r][c] == "*":
                    last = c - 1

        return [list(col)[::-1] for col in zip(*box)]     