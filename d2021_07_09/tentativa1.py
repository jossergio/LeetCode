# coding: utf-8

class Solution (object):

  def lengthOfLIS (self, nums):
    listaTabulada = list ()
    for a in range (len (nums)):
      listaTabulada.append (list ())
      listaTabulada [a].append (nums [a])
      for b in range (a + 1, len (nums)): # inicia no segundo elemento, o 1o já está
        if (listaTabulada [a][len (listaTabulada [a]) - 1] < nums [b]):
          listaTabulada [a].append (nums [b])
    tamanhos = map (len, listaTabulada)
    if (len (tamanhos) == 0): # Para o caso da lista vir vazia
      tamanhos.append (0)
    print "Lista Tabulada:"
    for t in  (listaTabulada):
      print (t)
    print "Tamanhos:"
    print tamanhos
    tamanhos.sort ()
    tamanhos.reverse ()
    return tamanhos [0]

processar = Solution ()

def teste (nomeLista, lista):
# Para fazer vários testes com listas diferentes
  print "===== Lista original ({} itens = {}):".format (nomeLista, len (lista))
  print lista

  print "===== Maior sequencia em n: {}".format (processar.lengthOfLIS (lista))
  print


n1 = [10, 30, 30, 40, 5, 50, 15, 5, 20, 35]
n2 = [1, 2, 3, 4, 5, 10, 11, 12]
n3 = [1, 2, 5, 6, 7, 8]
n4 = [0, 1, 0, 3, 2, 3] # Igual a um dos testes do LeetCode
n5 = [10, 9, 2, 5, 3, 7, 101, 18] # Igual ao modelo do LeetCode

# teste ("n1", n1)
# teste ("n2", n2)
# teste ("n3", n3)
teste ("n4", n4)
teste ("n5", n5)
teste ("Vazio", [])
teste ("Repetidos", [1, 1, 1, 1])

