# coding: utf-8

# Passada uma lista de números, retornar quantos triângulos podem ser formados
# Esse é o modelo de vera

class Solution (object):
  def trianglesNumber (self, nums):
    a, b, c, tamanho, temp, contar = 0, 0, 0, len (nums), [], 0
    maior, medio, menor = 0, 0, 0 # Não importa muito se há iguais
    for a in xrange (tamanho):
      for b in xrange (a + 1, tamanho):
        for c in xrange (b + 1, tamanho):
          temp = [nums [a], nums [b], nums [c]]
          temp.sort (reverse = True)
          maior, medio, menor = temp
          if (maior < (medio + menor)):
              contar += 1
    return contar

