# coding: utf-8

class Solution(object):
    def testar (self, palavra, puzzle):
        for letra in palavra:
            if puzzle.find (letra) == -1:
                return False
        return True

    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """

        retorno = list ()

        palavrasTrabalhadas = list ()
        for palavra in words:
            palavrasTrabalhadas.append ("".join (set (palavra)))

        for puzzle in puzzles:
            contador = 0
            for palavraTrabalhada in palavrasTrabalhadas:
                if palavraTrabalhada.find (puzzle [0]) == -1:
                    continue # Por definição do problema, a 1a letra de puzzle tem que estar na palavra
                if len (palavraTrabalhada) > 7: # Por definição, todo puzzle tem 7 letras
                # Se a palavra sem repetidos contém mais letras que o puzzle
                    continue
                if self.testar (palavraTrabalhada, puzzle):
                    contador += 1
            retorno.append (contador)

        return retorno

