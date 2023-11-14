class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letras = [chr (c) for c in range (ord ('a'), ord ('z') + 1)]
        indices = dict.fromkeys (letras, (-2, -2)) # Ainda não definido
        for c in letras:
            if indices [c][0] == -2:
                indices [c] = (s.find (str (c)), s.rfind (str (c))) # Irá definir para -1, caso não encontre
        resposta = 0
        for c in letras:
            if indices [c][0] != -1:
                tmp = set ()
                for i in range (indices [c][0] + 1, indices [c][1]):
                    tmp.add (s [i])
                resposta += len (tmp)
        return resposta
    
