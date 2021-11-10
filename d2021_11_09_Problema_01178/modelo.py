# coding: utf-8

class Solution(object):
    def testar (self, palavraOrdenada, puzzleOrdenado):
        indicePalavra = 0
        indicePuzzle = 0
        tamanhoPalavra = len (palavraOrdenada) # Irá usar mais de uma vez
        tamanhoPuzzle = len (puzzleOrdenado)
        while indicePalavra < tamanhoPalavra:
            while indicePuzzle < tamanhoPuzzle and puzzleOrdenado [indicePuzzle] != palavraOrdenada [indicePalavra]:
            # Observar que a ordem desse teste importa
                if puzzleOrdenado [indicePuzzle] > palavraOrdenada [indicePalavra]:
                # Com certeza, a partir daqui, não encontra mais
                    return False
                indicePuzzle += 1
            if not indicePuzzle < tamanhoPuzzle: # Estourou e não achou
                return False
            indicePalavra += 1
        return True

    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """

        retorno = list ()

        palavrasOrdenadas = list ()
        for palavra in words:
            palavraOrdenada = list (set (palavra))
            palavraOrdenada.sort ()
            palavrasOrdenadas.append (palavraOrdenada)

        for puzzle in puzzles:
            puzzleOrdenado = list (puzzle) # Por definição do problema, puzzle não tem letras repetidas
            puzzleOrdenado.sort ()
            contador = 0
            for palavraOrdenada in palavrasOrdenadas:
                try:
                    palavraOrdenada.index (puzzle [0])
                except:
                    continue # Se não encontrou a 1a letra...
                if len (palavraOrdenada) > len (puzzleOrdenado):
                # Se a palavra sem repetidos contém mais letras que o puzzle
                    continue
                if self.testar (palavraOrdenada, puzzleOrdenado):
                    contador += 1
            retorno.append (contador)

        return retorno

