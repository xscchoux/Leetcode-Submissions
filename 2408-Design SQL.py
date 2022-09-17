from collections import defaultdict
class SQL(object):

    def __init__(self, names, columns):
        """
        :type names: List[str]
        :type columns: List[int]
        """
        self.hmap = defaultdict(list)    

    def insertRow(self, name, row):
        """
        :type name: str
        :type row: List[str]
        :rtype: None
        """
        self.hmap[name].append(row)

    def deleteRow(self, name, rowId):
        """
        :type name: str
        :type rowId: int
        :rtype: None
        """
        pass

    def selectCell(self, name, rowId, columnId):
        """
        :type name: str
        :type rowId: int
        :type columnId: int
        :rtype: str
        """
        return self.hmap[name][rowId-1][columnId-1]


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# obj.insertRow(name,row)
# obj.deleteRow(name,rowId)
# param_3 = obj.selectCell(name,rowId,columnId)