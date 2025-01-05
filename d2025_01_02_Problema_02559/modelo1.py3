class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vogais = set (['a', 'e', 'i', 'o', 'u'])
        soma = [0] * len (words)
        for i, w in enumerate (words):
            if w [0] in vogais and w [-1] in vogais:
                if i == 0:
                    soma [0] = 1
                else:
                    soma [i] = soma [i - 1] + 1
            else:
                if i != 0:
                    soma [i] = soma [i - 1]
        return [soma [j] if i == 0 else soma [j] - soma [i - 1] for i, j in queries]
    
