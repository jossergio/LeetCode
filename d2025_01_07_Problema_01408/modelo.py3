class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort (key = lambda w: len (w))
        resposta = list ()
        for i, w in enumerate (words):
            for w2 in words [i + 1:]:
                if w2.find (w) != -1:
                    resposta.append (w)
                    break
        return resposta
