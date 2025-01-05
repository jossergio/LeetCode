class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vogais = set (['a', 'e', 'i', 'o', 'u'])
        soma = [0] * (len (words) + 1) # A primeira é sempre zero; evita um if == 0
        for i, w in enumerate (words):
            if w [0] in vogais and w [-1] in vogais:
                soma [i + 1] = soma [i] + 1 # Evita um if...
            else:
                soma [i + 1] = soma [i]
        return [soma [j + 1] - soma [i] for i, j in queries]
    
