#coding: utf-8

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """

        frequencia = dict ()
        for a in s:
            frequencia [a] = frequencia.get (a, 0) + 1
        retorno = ""
        while len (frequencia) > 0:
            letras = frequencia.keys ()
            indice = letras [0]
            valor = frequencia [indice]
            for j in letras [1:]:
                if frequencia [j] > valor: # Testa o mesmo valor do início
                    indice = j
                    valor = frequencia [j]
            retorno += indice * valor # Python
            frequencia.pop (indice)
        return retorno

