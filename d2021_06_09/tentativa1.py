# coding: utf-8

class Solution (object):

  def contarUnicos (self, nums):
    nums = list (set (nums))
    return len (nums)

  def longestConsecutive (self, nums):
    nums = list (set (nums)) # Tira os iguais
    nums.sort () # Ordena
    tamanho = len (nums) # Irá usar mais de uma vez
    if (tamanho > 0):
      maiorAcumulado = maior = 1 # ---->
      # Pressupõe uma única unidade ou o 1o item como uma sequência
    else:
      maiorAcumulado = maior = 0 # Lista vazia não tem sequência
    a = 0 # Inicializa
    while (a < (tamanho - 1)): # A lista inicia em 0 (zero); até o penúltimo
#      print "Dentro do laço item [{}]: {}".format (a, nums [a])
      a += 1 # Começa a procurar no próximo
      print "Iniciar comparação no item {} de valor {}".format (a - 1, nums [a - 1])
      while ((a < (tamanho)) and (nums [a] - nums [a - 1] == 1)):
        print "Dentro do laço interno item [{}]: {}".format (a, nums [a])
        a += 1
        maior += 1
      if (maior > maiorAcumulado):
        maiorAcumulado = maior
      maior = 1 # Reinicia o acumulador temporário
    return maiorAcumulado

processar = Solution ()

def teste (nomeLista, lista):
# Para fazer vários testes com listas diferentes  
  print "===== Lista original ({} itens = {}):".format (nomeLista, len (lista))
  print lista

  print "Itens únicos: {}".format (processar.contarUnicos (lista))

  lista = list (set (lista))
  lista.sort ()
  print "Lista únicos ordenada:"
  print lista

  print "===== Maior sequencia em n: {}".format (processar.longestConsecutive (lista))
  print


n1 = [10, 30, 30, 40, 5, 50, 15, 5, 20, 35]
n2 = [1, 2, 3, 4, 5, 10, 11, 12]
n3 = [1, 2, 5, 6, 7, 8]

teste ("n1", n1)
teste ("n2", n2)
teste ("n3", n3)

