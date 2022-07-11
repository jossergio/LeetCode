class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if not (len (nums) > 0):
            return 0 # O algoritmo precisa de um valor inicial
        
        heapq.heapify (nums)
        
        atual, maior = 1, 1 # Contadores
        
        anterior = nums [0]
        
        heapq.heappop (nums)
        
        while len (nums) > 0:
            
            n = nums [0]
            
            heapq.heappop (nums)
            
            # O Problema não fala, mas pode haver elementos iguais, que devem ser ignorados
            if n == anterior:
                continue # Não precisa atualizar nada dos valores das variáveis
            
            if n == anterior + 1:
                atual += 1
            else:
                maior = max (maior, atual)
                atual = 1
            
            anterior = n
        
        return max (maior, atual)
    
