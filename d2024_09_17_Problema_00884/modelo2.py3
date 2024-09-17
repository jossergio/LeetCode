class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        p1 = Counter (s1.split (" "))
        p2 = Counter (s2.split (" "))
        resposta = list ()
        for p, c in p1.items ():
            if c == 1 and p not in p2:
                resposta.append (p)
        for p, c in p2.items ():
            if c == 1 and p not in p1:
                resposta.append (p)
        return resposta
    
