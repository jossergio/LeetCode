# coding: utf-8

def contarMenor (nums):
  tamanho = len (nums)
  retorno = []
  print ("Tamanho da lista: {}".format (tamanho))
  for a in range (0, tamanho):
    retorno.append (0)
    for b in range (a + 1, tamanho):
      if (nums [b] < nums [a]):
        retorno [a] += 1
  return (retorno)

lista = [10, 9, 11, 30, 5, 4, 3, 2, 1]

print ("Lista: ")
print (lista)
print ("Retorno:")
print (contarMenor (lista))
