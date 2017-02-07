# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
class NestedInteger(object):
   def isInteger(self):
       """
       @return True if this NestedInteger holds a single integer, rather than a nested list.
       :rtype bool
       """

   def getInteger(self):
       """
       @return the single integer that this NestedInteger holds, if it holds a single integer
       Return None if this NestedInteger holds a nested list
       :rtype int
       """

   def getList(self):
       """
       @return the nested list that this NestedInteger holds, if it holds a nested list
       Return None if this NestedInteger holds a single integer
       :rtype List[NestedInteger]
       """

class NestedIterator(object):
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.list = self.tolist(nestedList)
        self.pos = 0
        self.length = len(self.list)

    def tolist(self, nestedList):
        result = []
        for i in range(len(nestedList)):
            if nestedList[i].isInteger():
                result.append(nestedList[i].getInteger())
            else:
                result.extend(self.tolist(nestedList[i].getList()))
        return result

    def next(self):
        """
        :rtype: int
        """
        self.pos += 1
        return self.list[self.pos - 1]

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.pos < self.length:
            return True
        return False


        # Your NestedIterator object will be instantiated and called as such:
        # i, v = NestedIterator(nestedList), []
        # while i.hasNext(): v.append(i.next())