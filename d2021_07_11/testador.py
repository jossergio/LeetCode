# coding: utf-8

# Faz testes com algum modelo

def testar (objeto, lista):
  resultado = [] # Uma lista vazia, para o resultado
  resultado.append ([]) # Para fazer comparações com o modelo do LeetCode
  for a in lista:
    objeto.addNum (a)
    resultado.append ([])
    resultado.append ([objeto.findMedian ()])
  return resultado

