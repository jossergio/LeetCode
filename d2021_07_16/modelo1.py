# coding: utf-8

class Solution (object):
  def testar (self, item, lista, target):
    a, b, c, d = item
    if (a + b + c + d) == target:
      item.sort () # O problema forçava isso
      try:
        lista.index (item)
      except ValueError: # Se não encontra o item, provoca esse erro
        lista.append (item)

  def fourSum (self, nums, target):
    a, b, c, d = 0, 0, 0, 0
    tamanho = len (nums) # Irá usar várias vezes
    lista = []
    for a in xrange (tamanho):
      for b in xrange (a + 1, tamanho):
        for c in xrange (b + 1, tamanho):
          for d in xrange (c + 1, tamanho):
            self.testar ([nums [a], nums [b], nums [c], nums [d]], lista, target)
    return lista

