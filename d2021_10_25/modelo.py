class MinStack(object):

    def __init__(self):
        self.pilha = list ()        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.pilha.append (val)

    def pop(self):
        """
        :rtype: None
        """
        self.pilha = self.pilha [0:len (self.pilha) - 1]

    def top(self):
        """
        :rtype: int
        """
        return self.pilha [len (self.pilha) - 1]

    def getMin(self):
        """
        :rtype: int
        """
        tmp = list (self.pilha)
        tmp.sort ()
        return tmp [0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

