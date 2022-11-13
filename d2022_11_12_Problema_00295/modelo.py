class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.acumulador = list ()

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.acumulador.append (num)

    def findMedian(self):
        """
        :rtype: float
        """
        self.acumulador.sort ()
        retorno = float (0)
        tamanho = len (self.acumulador) # Será utilizado várias vezes
        if (tamanho != 0):
            retorno = float (self.acumulador [tamanho //2])
            if ((tamanho % 2) == 0):
                retorno += float (self.acumulador [(tamanho // 2) - 1])
                retorno /= 2
        
        return retorno
            


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

