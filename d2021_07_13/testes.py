# coding: utf-8

#import modelo1
import modelo2

#executor = modelo1.Solution ()
executor = modelo2.Solution ()

def mostrar (serie):
  print serie
  print executor.findPeakElement (serie)
  print

mostrar ([1])

mostrar ([1, 2])

mostrar ([2, 1])

mostrar ([1, 3, 2])

mostrar ([1, 2, 3])

mostrar ([1, 2, 4, 3])

mostrar ([1, 2, 3, 10, 3, 2, 1])

mostrar ([ 1, 30, 1, 2, 3, 4, 5])

mostrar ([1, 30, 1, 2, 3, 4, 5, 6])

mostrar ([1, 2, 3, 4, 5, 6, 50, 8])

