class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        c = Counter (p)
        t = len (p)
        resposta = list ()
        for i in range (len (s) - t + 1):
            if Counter (s [i:i + t]) == c:
                resposta.append (i)
        return resposta
    
