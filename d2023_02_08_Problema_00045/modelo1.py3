class Solution:
    def jump(self, nums: List[int]) -> int:
        andamento = [-1] * len (nums)
        def buscar (item):
            if andamento [item] == -1:
                tmp = [10001] # Qualquer número maior que os limites do problema; Python não tem maxInt; referência
                if item == len (nums) - 1:
                    tmp += [0] # Também referência
                if nums [item] != 0:
                    for i in range (1, nums [item] + 1): # 1-begin; range não retorna o último valor
                        if item + i < len (nums):
                            tmp += [1 + buscar (item + i)]
                andamento [item] = min (tmp)
            return andamento [item]
        return buscar (0)
    
