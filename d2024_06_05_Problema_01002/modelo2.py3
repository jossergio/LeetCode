class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        letras = Counter (words [0])
        for w in words [1:]:
            tmp = dict ()
            for c, v in Counter (w).items ():
                if c in letras:
                    tmp [c] = v if v < letras [c] else letras [c]
            letras = tmp
        resposta = list ()
        for c, v in letras.items ():
            resposta.extend ([c] * v)
        return resposta
    
