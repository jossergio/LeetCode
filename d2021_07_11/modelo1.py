# coding: utf-8

class MedianFinder (object):

  def __init__ (self):
    self.acumulador = 0
    self.contador = 0

  def addNum (self, num):
    self.acumulador += num
    self.contador += 1

  def findMedian (self):
    retorno = 0
    if (self.contador != 0):
      retorno = float (self.acumulador) / self.contador
    return retorno

