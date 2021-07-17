# coding: utf-8

# Para testar modelo1

from testador import testar
import modelo1

teste1 = [1, 2, 3]
print "Testando:  {}".format (teste1)
print "Resultado: {}".format (testar (modelo1.MedianFinder (), teste1))

teste2 = [6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0]
print "Testando:  {}".format (teste2)
print "Resultado: {}".format (testar (modelo1.MedianFinder (), teste2))

