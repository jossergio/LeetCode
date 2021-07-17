# coding: utf-8

class MedianFinder (object):

  def __init__ (self):
    self.acumulador = list () # Não será um código eficiente

  def addNum (self, num):
    self.acumulador.append (num)

  def findMedian (self):
    retorno = 0
    if (len (self.acumulador) != 0):
      for a in self.acumulador: # Não falei que não seria um código eficiente?
        retorno += float (a) / len (self.acumulador) # Ineficiente muito, não?
    return retorno

