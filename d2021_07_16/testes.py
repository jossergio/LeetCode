# coding: utf-8

# import modelo1
import modelo2
# import modelo3

# executor = modelo1.Solution ()
executor = modelo2.Solution ()
# executor = modelo3.Solutio ()

def mostrar (lista, target):
  print "------"
  print "Exemplar: {}".format (lista)
  print "------"
  for a in executor.fourSum (lista, target):
    print a
  print "======"

mostrar ([1, 0, -1, 0, -2, 2], 0)

mostrar ([2, 2, 2, 2, 2], 8)

mostrar ([1, 0, -1, 0, -2, 2], 0) # Modelo de testes do LeetCode

