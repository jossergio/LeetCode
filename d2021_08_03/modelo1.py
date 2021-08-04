# coding: utf-8
# Rodar em python 3

class Solution (object):
# Estruturas auxiliares
    tamanho = 0
    numeros = list ()
    listagem = list ()

    def adicionar (self, q):
        r = q.copy ()
        r.sort ()
        encontrado = False
        for a in self.listagem:
            if a == r:
                encontrado = True
                break
        if not encontrado:
            self.listagem.append (r)

    def conjunto (self, q, i, c):
        if c > 0:
            for a in range (i, self.tamanho):
                r = q.copy ()
                r.append (self.numeros [a])
                self.conjunto (r, a + 1, c - 1)
        else:
            self.adicionar (q)

# Código principal
    def subsetWithDup (self, nums):
        self.listagem.append (list ()) # A lista vazia faz parte da solução
        self.tamanho = len (nums)
        # if self.tamanho > 0:
        #     self.listagem.append (nums) # Também
        self.numeros = nums
        for a in range (self.tamanho):
            r = list ()
            r.append (self.numeros [a])
            for b in range (0, self.tamanho - a):
                self.conjunto (r, a + 1, b)
        return self.listagem

