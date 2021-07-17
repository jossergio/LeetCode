# coding: utf-8

def contarMenor (nums):
  retorno = [0 for x in nums]
  l = 0
  while (len (nums) > 0):
    item = nums.pop (0)
    for a in nums:
      if (a < item):
        retorno [l] += 1
    l += 1
  return (retorno)

lista = [10, 9, 11, 30, 5, 4, 3, 2, 1]

print ("Lista: ")
print (lista)
print ("Retorno:")
print (contarMenor (lista))
