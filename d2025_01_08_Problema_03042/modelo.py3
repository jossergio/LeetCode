class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        resposta = 0
        for i, w in enumerate (words):
            for w2 in words [i + 1:]:
                if len (w) <= len (w2):
                    t = len (w)
                    if w == w2 [:t] and w == w2 [-t:]:
                        resposta += 1
        return resposta
