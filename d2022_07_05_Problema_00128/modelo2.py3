class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if len (nums) == 0:
            return 0 # O algoritmo precisa de, pelo menos, um elemento
        
        nums = list (set (nums)) # Remove os iguais
        nums.sort () # Precisa estar ordenado
        
        atual, maior = 1, 1 # Contadores
        
        for i in range (1, len (nums)): # Inicia no 2o
            if (nums [i] - nums [i - 1]) == 1:
                atual += 1
            else:
                maior = max (maior, atual)
                atual = 1
                
        return max (maior, atual)
    
