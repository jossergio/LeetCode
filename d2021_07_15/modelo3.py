# coding: utf-8

# Passada uma lista de números, retornar quantos triângulos podem ser formados
# Esse modelo é para ver se otimiza o tempo, pois, ficou lento o primeiro

class Solution (object):
  def iteracoes (self, nums):
    contar, tamanho = 0, len (nums) # Inicialmente, só um teste para os laços
    for a in xrange (tamanho):
      for b in xrange (a + 1, tamanho):
        for c in xrange (b + 1, tamanho):
          contar += 1
    return contar

