# coding: utf-8

class MedianFinder (object):

  def __init__ (self):
    self.acumulador = 0
    self.contador = 0

  def addNum (self, num):
    restaurado = int (self.acumulador) * self.contador # Que teste sem sentido!
    self.contador += 1
    novaMedia = float ((restaurado / self.contador) + (num / self.contador)) # Lógica?
    self.acumulador = novaMedia

  def findMedian (self):
    return self.acumulador

