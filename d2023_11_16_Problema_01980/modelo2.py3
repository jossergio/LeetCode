class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        t = len (nums [0]) # São todos do mesmo tamanho

        def decimal (s: str) -> int:
            i = 0
            soma = 0
            for c in s[::-1]:
                soma += int (c) * 2 ** i
                i += 1
            return soma

        def binario (i: int) -> int:
            s = ""
            while (i > 0):
                r = i % 2
                s += str (r)
                i //= 2
            return s [::-1].zfill (t)
        
        # Fiz em linhas separadas, por organização
        todos = set ([a for a in range (2 ** t)])
        todos = todos.difference (set ([decimal (a) for a in nums]))
        return binario (todos.pop ())

