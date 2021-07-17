# coding: utf-8

def contarMenor (nums):
  retorno = []
  while (len (nums) > 0):
    item = nums.pop (0)
    retorno.append ((lambda i, n: len ([x for x in n if x < i]))(item, nums))
  return (retorno)

lista = [10, 9, 11, 30, 5, 4, 3, 2, 1]

print ("Lista: ")
print (lista)
print ("Retorno:")
print (contarMenor (lista))
