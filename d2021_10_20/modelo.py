#coding: utf-8

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        tamanho = len (s) # Irá utilizar muitas vezes
        a = 0
        retorno = list ()
        while (a < tamanho):
            tmp = "" # Espaço vazio
            while a < tamanho and s [a] == " ": # Atentar ao detalhe da ordem do and
                a += 1
            while a < tamanho and (s [a].isalpha () or s [a].isdigit ()):
                tmp += s [a]
                a += 1
            if (len (tmp) > 0):
                retorno.append (tmp)
        retorno.reverse ()
        return " ".join (retorno)

