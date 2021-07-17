# coding: utf-8

class MedianFinder (object):

  def __init__ (self):
    self.acumulador = list ()

  def addNum (self, num):
    self.acumulador.append (num)
    self.acumulador.sort ()

  def findMedian (self):
    retorno = float (0)
    tamanho = len (self.acumulador) # Será usado várias vezes
    if (tamanho != 0):
      # Python inicia listas em 0
      retorno = float (self.acumulador [(tamanho // 2)])
      print "Tamanho em {} resultado em {}".format (tamanho, retorno)
      if ((tamanho % 2) == 0): # Par
        retorno += float (self.acumulador [(tamanho // 2) - 1])
        retorno /= 2
        print "Par: tamanho em {} resultado em {}".format (tamanho, retorno)
    return retorno

