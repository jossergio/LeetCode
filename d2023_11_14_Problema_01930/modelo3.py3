class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letras = [chr (c) for c in range (ord ('a'), ord ('z') + 1)]
        indices = dict.fromkeys (letras, (-2, -2)) # Ainda não definido
        for c in letras:
            if indices [c][0] == -2:
                indices [c] = (s.find (str (c)), s.rfind (str (c))) # Irá definir para -1, caso não encontre
        resposta = 0
        for i, j in [(b [0], b [1]) for a, b in indices.items () if b [0] != -1]:
            tmp = set ()
            for i in range (i + 1, j):
                tmp.add (s [i])
            resposta += len (tmp)
        return resposta
    
