class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        listas = [(Counter (s), i) for i, s in enumerate (words)]
        retirar = list ()
        for i in range (1, len (words)):
            if listas [i][0] == listas [i - 1][0]:
                retirar.append (i)
        retirar.reverse () # Questão de reorganização dos índices a cada retirada
        for i in retirar:
            words.pop (i)
        return words
