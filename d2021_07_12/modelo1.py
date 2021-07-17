# coding: utf-8

class Solution (object):
  def isIsomorphic (self, s, t):
    # A definição do problema cita que len (s) == len (t)
    contador = 0 # Ao final, contador tem que ser o tamanho das strings
    dicionario = {}
    for i in xrange (len (s)):
      if (s [i] in dicionario):
        if (t [i] == dicionario [s [i]]):
          contador += 1
      else:
        if (not t [i] in dicionario.values ()):
          dicionario [s [i]] = t [i]
          contador += 1
    return (contador == len (s))

solucao = Solution ()

print solucao.isIsomorphic ("egg", "add")

print solucao.isIsomorphic ("foo", "bar")

print solucao.isIsomorphic ("paper", "title")

print solucao.isIsomorphic ("badc", "baba")

