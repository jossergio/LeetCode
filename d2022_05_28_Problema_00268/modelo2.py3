class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        tamanho = len (nums)
        
        for i in range (0, tamanho):
            
            while nums [i] != i:
                if nums [i] != tamanho:
                    tmp1, tmp2 = nums [i], nums [nums [i]]
                    if tmp2 == tamanho:
                        break # Provavelmente será o 0
                    nums [i] = tmp2
                    nums [tmp1] = tmp1
                    # nums [i], nums [nums [i]] = nums [nums [i]], nums [i] # Permuta
                else:
                    if i == tamanho - 1: # Chegou ao final, o vetor deve estar ordenado, nesse ponto
                        for j in range (0, tamanho): # range não trás o último
                            if nums [j] != j:
                                return j
                            
                    while nums [tamanho - 1] != tamanho:
                        tmp1, tmp2 = nums [tamanho - 1], nums [nums [tamanho - 1]]
                        if tmp1 == tmp2:
                            # Entraria em um laço. Só permuta i com o último
                            tmp1 = nums [tamanho - 1]
                            tmp2 = nums [i]
                            nums [tamanho - 1] = tmp2
                            nums [i] = tmp1
                        else:
                            nums [tamanho - 1] = tmp2
                            nums [tmp1] = tmp1

                        # nums [nums [tamanho - 1]], nums [tamanho - 1] = nums [tamanho - 1], nums [nums [tamanho - 1]] # Permuta com o último
                
        return len (nums)
    
