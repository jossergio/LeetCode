# coding: utf-8
# Retorna topos (ou picos) em uma lista
# Modelo 1

class Solution (object):
  def findPeakElement (self, nums):
    posicao, tamanho, limite, encontrado = 1, len (nums), len (nums) // 2, 0
    print "Tamanho: {}, Limite: {}".format (tamanho, limite)
    if tamanho == 2:
      if nums [1] > nums [0]: # O contrário já está em encontrado! Think.
        encontrado = 1
    elif tamanho >= 3: # Pois, poderia ser 1, que já é padrão! Think.
      if nums [tamanho - 1] > nums [tamanho - 2]: # Think... O retorno padrão é zero
        encontrado = tamanho - 1
      else:
        print "Posição 1: {}, Posição 2: {}".format (posicao, tamanho - posicao - 1)
        while (posicao <= limite) and (encontrado == 0):
          if (nums [posicao - 1] < nums [posicao]) and (nums [posicao] > nums [posicao + 1]):
            encontrado = posicao # Encontrou do início para o meio
          elif (nums [tamanho - posicao - 2] < nums [tamanho - posicao - 1]) and (nums [tamanho - posicao - 1] > nums [tamanho - posicao]):
            encontrado = tamanho - posicao - 1
          posicao += 1
    return encontrado

