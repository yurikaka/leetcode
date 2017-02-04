class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.list = []
        self.mini = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.list.append(x)
        if not self.mini:
            self.mini.append(x)
            return
        if self.mini[-1] >= x:
            self.mini.append(x)


    def pop(self):
        """
        :rtype: void
        """
        y = self.list.pop()
        if y == self.mini[-1]:
            self.mini.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.list[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.mini[-1]



        # Your MinStack object will be instantiated and called as such:
        # obj = MinStack()
        # obj.push(x)
        # obj.pop()
        # param_3 = obj.top()
        # param_4 = obj.getMin()