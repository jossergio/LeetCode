# coding: utf-8

class Solution (object):
  def fourSum (self, nums, target):
    novoNums = list (nums)
    lista = []
    while len (novoNums) > 0:
      # Antes de fazer uma chamada, pop já modificou novoNums
      self.nivel1 (lista, novoNums.pop (0), novoNums, target)
    return lista

  def nivel1 (self, lista, a, nums, target):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivel2 (lista, a, novoNums.pop (0), novoNums, target)

  def nivel2 (self, lista, a, b, nums, target):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivel3 (lista, a, b, novoNums.pop (0), novoNums, target)

  def nivel3 (self, lista, a, b, c, nums, target):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivelFinal (lista, a, b, c, novoNums.pop (0), target)

  def nivelFinal (self, lista, a, b, c, d, target):
    if (a + b + c + d) == target:
      item = [a, b, c, d]
      item.sort () # O problema forçava isso
# Uma ótima forma de fazer uma procura otimizada pelo "não encontrar"
# Uma outra forma seria um laço, variáveis etc
      try:
        lista.index (item)
      except ValueError: # Se não encontra o item, provoca esse erro
        lista.append (item)

