class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        valores = defaultdict (int)
        for w in words:
            for i in range (len (w)):
                valores [w [:i + 1]] += 1
        resposta = list ()
        for w in words:
            soma = 0
            for i in range (len (w)):
                soma += valores [w [:i + 1]]
            resposta.append (soma)
        return resposta
    
