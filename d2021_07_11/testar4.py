# coding: utf-8

# Para testar modelo 4

from testador import testar
import modelo4

teste1 = [1]
print "Testando:  {}".format (teste1)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste1))
print

teste2 = [1, 2]
print "Testando:  {}".format (teste2)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste2))
print

teste3 = [1, 2, 3]
print "Testando:  {}".format (teste3)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste3))
print
teste4 = [1, 2, 3, 4]
print "Testando:  {}".format (teste4)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste4))
print

teste5 = [1, 2, 3]
print "Testando:  {}".format (teste5)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste5))
print

teste6 = [6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0]
print "Testando:  {}".format (teste6)
print "Resultado: {}".format (testar (modelo4.MedianFinder (), teste6))
print

