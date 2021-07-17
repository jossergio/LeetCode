# coding: utf-8
# Retorna topos (ou picos) em uma lista
# Modelo 2 - Recursivo

class Solution (object):
  def findRecurs (self, inicio, final, nums):
    meio = (inicio + final) // 2
    encontrado = 0
    
    print "Meio: {}; Início: {}; Final: {}; Lista: {}".format (meio, inicio, final, nums [inicio:final + 1])
    if (final - inicio) >= 2: # Tem, pelo menos, três e meio é o do meio
      if (nums [meio - 1] < nums [meio]) and (nums [meio] > nums [meio + 1]):
        encontrado = meio
      else:
        encontrado = self.findRecurs (meio, final, nums)
        if encontrado == 0: # Tenta do outro lado
          encontrado = self.findRecurs (inicio, meio, nums)

    return encontrado # findRecurs

  def findPeakElement (self, nums):
    tamanho, encontrado = len (nums), 0
    if tamanho == 2:
      if nums [1] > nums [0]: # O contrário já está em encontrado! Think.
        encontrado = 1 # Segunda posição (ou a última)
    elif tamanho == 3: # Para fazer o teste das pontas
      if (nums [0] < nums [1]) and (nums [1] > nums [2]):
        encontrado = 1
      elif (nums [2] > nums [1]): # O último dos três é o maior (ou não, não importa)
        encontrado = 2
    elif tamanho > 3: # Porque o tamanho 1 não é testado
      if nums [tamanho - 1] > nums [tamanho - 2]: # Que mágica!
        encontrado = tamanho - 1
      elif not (nums [0] > nums [1]): # Mágica com o primeiro elemento!
          encontrado = self.findRecurs (0, tamanho - 1, nums)# tamanho - 1 = posição do último

    return encontrado # findPeakElement

