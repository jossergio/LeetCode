class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        vetor = list ()
        t = len (nums [0]) # Padrão
        def gerar (n, acum):
            if n < t:
                gerar (n + 1, acum + "0")
                gerar (n + 1, acum + "1")
            else:
                vetor.append (acum)
        gerar (0, "")
        return list (set (vetor) - set (nums))[0] # Qualquer um
    