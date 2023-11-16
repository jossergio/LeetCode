class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        t = len (nums [0]) # Todos são do mesmo tamanho
        
        def binario (i: int) -> int:
            s = ""
            while (i > 0):
                r = i % 2
                s += str (r)
                i //= 2
            return s [::-1].zfill (t)
        
        todos = set ([binario (a) for a in range (2 ** len (nums))])
        # Poderia ter feito em uma linha, sem utilizar uma variável.
        # Mas ficaria meio confusa.
        return todos.difference (set (nums)). pop ()

