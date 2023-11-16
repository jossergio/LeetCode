class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        t = len (nums [0]) # Todos são do mesmo tamanho
        for i in range (2 ** t):
            tmp = bin (i)[2:].zfill (t)
            if not tmp in nums:
                return tmp
        return "" # Não chegará aqui

