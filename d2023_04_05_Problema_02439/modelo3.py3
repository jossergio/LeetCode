class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        sair = False
        while not sair:
            sair = True # Laço bobo
            for i in range (1, len (nums)):
                if nums [i] > nums [i - 1]:
                    quoc, resto = divmod (nums [i] + nums [i - 1], 2)
                    nums [i - 1] = quoc + resto # Se sobrou, entra aqui
                    nums [i] = quoc
                    sair = False
        return max (nums)
    
