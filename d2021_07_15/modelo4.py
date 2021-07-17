# coding: utf-8

# Passada uma lista de números, retornar quantos triângulos podem ser formados
# Esse é o modelo para usar chamadas a funções para ver se fica mais rápido
# A ideia é reduzir iteratividades dos laços aninhados

class Solution (object):
  def triangleNumberLevel3 (self, a, b, c):
    count = 0
    temp = [a, b, c]
    temp.sort (reverse = True) # Fiz testes e não mudou muito a performance
    if (temp [0] < (temp [1] + temp [2])):
      count = 1
    return count

  def triangleNumberLevel2 (self, a, b, remainNums):
    newNums = list (remainNums)
    count = 0
    while (len (newNums) >= 1):
      count += self.triangleNumberLevel3 (a, b, newNums.pop (0))
    return count
    
  def triangleNumberLevel1 (self, a, remainNums):
    count = 0
    newNums = list (remainNums)
    while (len (newNums) >= 2):
      count += self.triangleNumberLevel2 (a, newNums.pop (0), newNums)
    return count
  
  def trianglesNumber (self, nums):
    count = 0
    newNums = [i for i in nums if i > 0] # Cria uma lista nova e elimina negativos e zero
    while (len (newNums) >= 3):
      count += self.triangleNumberLevel1 (newNums.pop (0), newNums)
    return count

