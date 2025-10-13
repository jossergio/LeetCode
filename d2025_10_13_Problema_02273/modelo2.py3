class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ordenados = [sorted (w) for w in words]
        ficam = [0] # O 1o sempre fica
        for i in range (1, len (words)):
            if ordenados [i] != ordenados [i - 1]:
                ficam.append (i)
        return [words [i] for i in ficam]
