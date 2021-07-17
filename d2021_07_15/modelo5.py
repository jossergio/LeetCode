# coding: utf-8

# Passada uma lista de números, retornar quantos triângulos podem ser formados
# Esse é o modelo para usar chamadas a funções para ver se fica mais rápido
# A ideia é reduzir iteratividades dos laços aninhados
# Esse modelo mostra os triângulos formados, para comparação

class Solution (object):
  def trianglesLevel3 (self, a, b, c):
    temp = [a, b, c]
    temp2 = []
    temp.sort (reverse = True) # Fiz testes e não mudou muito a performance
    if (temp [0] < (temp [1] + temp [2])):
      temp2 = [a, b, c]
    return temp2

  def trianglesLevel2 (self, a, b, remainNums):
    temp = []
    newNums = list (remainNums)
    while (len (newNums) >= 1):
      temp.append (self.trianglesLevel3 (a, b, newNums.pop (0)))
    return temp
    
  def trianglesLevel1 (self, a, remainNums):
    temp = []
    newNums = list (remainNums)
    while (len (newNums) >= 2):
      temp.extend (self.trianglesLevel2 (a, newNums.pop (0), newNums))
    return temp
  
  def triangles (self, nums):
    temp = []
    newNums = list (nums)
    while (len (newNums) >= 3):
      temp.extend (self.trianglesLevel1 (newNums.pop (0), newNums))
    return [i for i in temp if len (i) > 0]

