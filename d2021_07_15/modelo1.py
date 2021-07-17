# coding: utf-8

# Passada uma lista de números, retornar quantos triângulos podem ser formados
# Esse modelo é só para testes, pois, retorna os triângulos formados

class Solution (object):
  def triangles (self, nums):
    a, b, c, tamanho, triangulosFormados, temp = 0, 0, 0, len (nums), [], []
    maior, medio, menor = 0, 0, 0 # Não importa muito se há iguais
    for a in xrange (tamanho):
      for b in xrange (a + 1, tamanho):
        for c in xrange (b + 1, tamanho):
          temp = [nums [a], nums [b], nums [c]]
          temp.sort (reverse = True)
          maior, medio, menor = temp
          # print "Temp: {}, Maior: {}, Medio: {}, Menor: {}".format (temp, maior, medio, menor)
          if (maior < (medio + menor)):
              triangulosFormados.append ([nums [a], nums [b], nums [c]])
    return triangulosFormados

