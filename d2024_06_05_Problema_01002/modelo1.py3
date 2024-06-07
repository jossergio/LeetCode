class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        letras = Counter (words [0])
        for i in range (1, len (words)):
            tmp = Counter (words [i])
            tmp2 = set ([c for c in letras.keys ()]).intersection (set ([c for c in tmp.keys ()]))
            tmp3 = dict ()
            for c in tmp2:
                tmp3 [c] = letras [c] if letras [c] < tmp [c] else tmp [c]
            letras = tmp3
        resposta = list ()
        for c, v in letras.items ():
            for j in range (0, v):
                resposta.append (c)
        return resposta
    
