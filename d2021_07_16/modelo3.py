# coding: utf-8

class Solution (object):
  lista = []
  objetivo = 0

  def fourSum (self, nums, target):
    self.objetivo = target
    self.lista = [] # Se irá começar um novo, tem que limpar (global)
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivel1 (novoNums.pop (0), novoNums)
    return self.lista

  def nivel1 (self, a, nums):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivel2 (a, novoNums.pop (0), novoNums)

  def nivel2 (self, a, b, nums):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivel3 (a, b, novoNums.pop (0), novoNums)

  def nivel3 (self, a, b, c, nums):
    novoNums = list (nums)
    while len (novoNums) > 0:
      self.nivelFinal (a, b, c, novoNums.pop (0))

  def nivelFinal (self, a, b, c, d):
    if (a + b + c + d) == self.objetivo:
      item = [a, b, c, d]
      item.sort () # O problema forçava isso
# Uma ótima forma de fazer uma procura otimizada pelo "não encontrar"
# Uma outra forma seria um laço, variáveis etc
      try:
        self.lista.index (item)
      except ValueError: # Se não encontra o item, provoca esse erro
        self.lista.append (item)
    
