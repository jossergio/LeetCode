class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letras = set (s)
        indices = dict ()
        for c in letras:
            indices [c] = (s.find (str (c)), s.rfind (str (c)))
        resposta = 0
        for i, j in [(b [0], b [1]) for a, b in indices.items ()]:
            resposta += len (set (s [i + 1:j]))
        return resposta
    
