# coding: utf-8

class Solution (object):

  def longestConsecutive (self, nums):
    nums = list (set (nums)) # Tira os iguais
    nums.sort () # Ordena
    iterador = iter (nums)
    try:
      maiorAcumulado = maior = 1
      anterior = next (iterador)
    except StopIteration:
      maiorAcumulado = 0 # A lista está vazia
    except:
      print "Algum outro erro"
    if (maiorAcumulado > 0):
      while (True):
        try:
          atual = next (iterador)
        except StopIteration:
          break; # Encerra o laço "Infinito"
        except:
          print "Algum outro erro no laço"
        if ((atual - anterior) == 1):
          print "Encontrou uma sequência {} e {}".format (anterior, atual)
          maior += 1
        else:
          print "Reiniciando contador de sequência {} e {}".format (anterior,atual)
          maior = 1 # Reinicia o contador
        anterior = atual # Guarda o anterior
        if (maior > maiorAcumulado):
          maiorAcumulado = maior
        
    return maiorAcumulado

processar = Solution ()

def teste (nomeLista, lista):
# Para fazer vários testes com listas diferentes  
  print "===== Lista original ({} itens = {}):".format (nomeLista, len (lista))
  print lista

  print "===== Maior sequencia em n: {}".format (processar.longestConsecutive (lista))
  print


n1 = [10, 30, 30, 40, 5, 50, 15, 5, 20, 35]
n2 = [1, 2, 3, 4, 5, 10, 11, 12]
n3 = [1, 2, 5, 6, 7, 8]

teste ("Vazia", [])
teste ("n1", n1)
teste ("n2", n2)
teste ("n3", n3)

